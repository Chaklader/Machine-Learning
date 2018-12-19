import os
import random
import time

import pygame

from agent import LearningAgent
from environment import Environment

class SimulatorNoGraphics(object):
    """
    A Simulator that doesn't use pygame; instead, it just steps its Environment
    until the Environment is done.
    """
    def __init__(self, env):
        self.env = env

    def run(self, n_trials=100):
        # Keep track of primary agent's performance
        pa_performances = []

        # Run your trials
        for trial in xrange(n_trials):
            self.env.reset()
            while True:
                self.env.step()
                if self.env.done:
                    if self.env.primary_agent is None:
                        break
                    else:
                        perf = self.env.primary_agent_performance()
                        pa_performances.append(perf)
                        break
        return pa_performances if pa_performances else None


class Simulator(object):
    """PyGame-based simulator to create a dynamic environment."""

    colors = {
        'black'   : (  0,   0,   0),
        'white'   : (255, 255, 255),
        'red'     : (255,   0,   0),
        'green'   : (  0, 255,   0),
        'blue'    : (  0,   0, 255),
        'cyan'    : (  0, 200, 200),
        'magenta' : (200,   0, 200),
        'yellow'  : (255, 255,   0),
        'orange'  : (255, 128,   0)
    }

    def __init__(self, env, size=None, frame_delay=10, update_delay=1.0):
        self.env = env
        self.size = size if size is not None else self.env.pixel_dimensions
        self.width, self.height = self.size
        self.frame_delay = frame_delay

        self.bg_color = self.colors['white']
        self.road_width = 5
        self.road_color = self.colors['black']

        self.quit = False
        self.start_time = None
        self.current_time = 0.0
        self.last_updated = 0.0
        self.update_delay = update_delay

        pygame.init()
        self.screen = pygame.display.set_mode(self.size)

        self.agent_sprite_size = (32, 32)
        self.agent_circle_radius = 10  # for simple representation
        for agent in self.env.agent_states:
            agent._sprite = pygame.transform.smoothscale(pygame.image.load(os.path.join("images", "car-{}.png".format(agent.color))), self.agent_sprite_size)
            agent._sprite_size = (agent._sprite.get_width(), agent._sprite.get_height())

        self.font = pygame.font.Font(None, 28)
        self.paused = False

    def run(self, n_trials=1):
        self.quit = False

        # Keep track of primary agent's performance
        pa_performances = []

        # Run your trials
        for trial in xrange(n_trials):
            print "Simulator.run(): Trial {}".format(trial)  # [debug]
            self.env.reset()
            self.current_time = 0.0
            self.last_updated = 0.0
            self.start_time = time.time()
            while True:
                self.current_time = time.time() - self.start_time
                #print "Simulator.run(): current_time = {:.3f}".format(self.current_time)
                try:
                    # Handle events
                    for event in pygame.event.get():
                        if event.type == pygame.QUIT:
                            self.quit = True
                        elif event.type == pygame.KEYDOWN:
                            if event.key == 27:  # Esc
                                self.quit = True
                            elif event.unicode == u' ':
                                self.paused = True

                    if self.paused:
                        self.pause()

                    # Update environment
                    if self.current_time - self.last_updated >= self.update_delay:
                        self.env.step()
                        self.last_updated = self.current_time

                    # Render and sleep
                    self.render()
                    pygame.time.wait(self.frame_delay)
                except KeyboardInterrupt:
                    self.quit = True
                finally:
                    if self.quit:
                        break
                    elif self.env.done:
                        if self.env.primary_agent is None:
                            break
                        else:
                            pa_performances.append(self.env.primary_agent_performance())
                            break

            if self.quit:
                break

        return pa_performances if pa_performances else None

    def render(self):
        # Clear screen
        self.screen.fill(self.bg_color)

        # Draw elements
        # * Static elements
        for road in self.env.roads:
            pygame.draw.line(self.screen, self.road_color, (road[0][0] * self.env.block_size, road[0][1] * self.env.block_size), (road[1][0] * self.env.block_size, road[1][1] * self.env.block_size), self.road_width)

        for intersection, traffic_light in self.env.intersections.iteritems():
            pygame.draw.circle(self.screen, self.road_color, (intersection[0] * self.env.block_size, intersection[1] * self.env.block_size), 10)
            if traffic_light.state:  # North-South is open
                pygame.draw.line(self.screen, self.colors['green'],
                    (intersection[0] * self.env.block_size, intersection[1] * self.env.block_size - 15),
                    (intersection[0] * self.env.block_size, intersection[1] * self.env.block_size + 15), self.road_width)
            else:  # East-West is open
                pygame.draw.line(self.screen, self.colors['green'],
                    (intersection[0] * self.env.block_size - 15, intersection[1] * self.env.block_size),
                    (intersection[0] * self.env.block_size + 15, intersection[1] * self.env.block_size), self.road_width)

        # * Dynamic elements
        for agent, state in self.env.agent_states.iteritems():
            # Compute precise agent location here (back from the intersection some)
            agent_offset = (2 * state['heading'][0] * self.agent_circle_radius, 2 * state['heading'][1] * self.agent_circle_radius)
            agent_pos = (state['location'][0] * self.env.block_size - agent_offset[0], state['location'][1] * self.env.block_size - agent_offset[1])
            agent_color = self.colors[agent.color]
            if hasattr(agent, '_sprite') and agent._sprite is not None:
                # Draw agent sprite (image), properly rotated
                rotated_sprite = agent._sprite if state['heading'] == (1, 0) else pygame.transform.rotate(agent._sprite, 180 if state['heading'][0] == -1 else state['heading'][1] * -90)
                self.screen.blit(rotated_sprite,
                    pygame.rect.Rect(agent_pos[0] - agent._sprite_size[0] / 2, agent_pos[1] - agent._sprite_size[1] / 2,
                        agent._sprite_size[0], agent._sprite_size[1]))
            else:
                # Draw simple agent (circle with a short line segment poking out to indicate heading)
                pygame.draw.circle(self.screen, agent_color, agent_pos, self.agent_circle_radius)
                pygame.draw.line(self.screen, agent_color, agent_pos, state['location'], self.road_width)
            if agent.get_next_waypoint() is not None:
                self.screen.blit(self.font.render(agent.get_next_waypoint(), True, agent_color, self.bg_color), (agent_pos[0] + 10, agent_pos[1] + 10))
            if state['destination'] is not None:
                pygame.draw.circle(self.screen, agent_color, (state['destination'][0] * self.env.block_size, state['destination'][1] * self.env.block_size), 6)
                pygame.draw.circle(self.screen, agent_color, (state['destination'][0] * self.env.block_size, state['destination'][1] * self.env.block_size), 15, 2)

        # * Overlays
        text_y = 10
        for text in self.env.status_text.split('\n'):
            self.screen.blit(self.font.render(text, True, self.colors['red'], self.bg_color), (100, text_y))
            text_y += 20

        # Flip buffers
        pygame.display.flip()

    def pause(self):
        abs_pause_time = time.time()
        pause_text = "[PAUSED] Press any key to continue..."
        self.screen.blit(self.font.render(pause_text, True, self.colors['cyan'], self.bg_color), (100, self.height - 40))
        pygame.display.flip()
        print pause_text  # [debug]
        while self.paused:
            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    self.paused = False
            pygame.time.wait(self.frame_delay)
        self.screen.blit(self.font.render(pause_text, True, self.bg_color, self.bg_color), (100, self.height - 40))
        self.start_time += (time.time() - abs_pause_time)


def initialize_simulator_environment(agent_params=None, graphics=False,
        use_deadline=True):
    if agent_params is None:
        agent_params = {}

    e = Environment()
    sim = Simulator(e) if graphics else SimulatorNoGraphics(e)
    a = e.create_agent(LearningAgent, **agent_params)
    e.set_primary_agent(a, enforce_deadline=use_deadline)
    return sim, e


def run_with_params(agent_params=None, **kwargs):
    """
    Run some specified number of trials with a LearningAgent that's learning.

    Supported agent_param keys: see LearningAgent.__init__

    Supported kwargs (default):
    - use_deadline: should the simulation enforce a deadline? (True)
    - graphics: should a pygame window show the simulation graphics? (False)
    - num_trials: how many trials should be run? (100)

    Returns:
    - agent_performance: a list of PrimaryAgentPerformances, one for each trial
    - agent_info: a dictionary of agent parameters and their values
    """
    if agent_params is None:
        agent_params = {}

    use_deadline = kwargs.pop('use_deadline', True)
    graphics = kwargs.pop('graphics', False)
    num_trials = kwargs.pop('num_trials', 100)
    if kwargs:
        raise TypeError('Unexpected **kwargs: %r' % kwargs)

    sim, e = initialize_simulator_environment(agent_params, graphics, use_deadline)
    agent_performance = sim.run(num_trials)
    agent_info = e.primary_agent.agent_info
    return agent_performance, agent_info
