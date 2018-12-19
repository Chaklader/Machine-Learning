from collections import namedtuple
from itertools import product
import random

from environment import Agent
from planner import RoutePlanner
from strategies import *


# Agent's state: the current traffic light, and where it should go next
AgentState = namedtuple('AgentState', ('light', 'next_waypoint'))


class LearningAgent(Agent):
    """
    An agent that learns to drive in the smartcab world via Q-Learning.

    Q-Learning maps state-action pairs to values, based on the feedback
    received from the environment in response to taking actions from various
    states.

    The main data structure for this is q_map, a dictionary that maps
    AgentState -> {action -> Q-value}. When the agent is in learning mode
    (controlled by instance variable learning), these Q values are updated as a
    weighted average of the current value and the discounted, predicted future
    value of its new state.
    """

    def __init__(self, env, **kwargs):
        # Simulation infrastructure
        super(LearningAgent, self).__init__(env)
        self.color = 'red'
        self.planner = RoutePlanner(self.env, self)

        # Q-Learning data structures
        self.current_state = None

        # Establish Q-Learning parameters based on supplied keyword-arguments
        # - alpha: learning rate, i.e. how much of q-value depends on estimated
        #          future versus seen past
        # - gamma: discount rate, i.e. how much do you value future rewards
        # - q_boost: added to initial Q-value when action == next_waypoint
        self.q_boost = kwargs.pop('q_boost', 0.0)
        self.alpha = kwargs.pop('alpha', 0.5)
        self.gamma = kwargs.pop('gamma', 0.8)
        self.strategy = kwargs.pop('strategy', explorer)
        if kwargs:
            raise TypeError("Unexpected **kwargs: %r" % kwargs)

        # Initialize Q-values for all possible states
        self.q_map = self.make_initial_q_map(self.strategy, self.q_boost)

        # Should the agent update its q_map based on environment feedback?
        self.learning = True

        # Performance tracking
        self.positive_reward_earned = 0
        self.negative_reward_earned = 0

        # How many times has this agent been reset?
        # This is equivalent to how many trials the agent has participated in
        self.num_resets = 0

    def reset(self, destination=None):
        """Get the agent ready for the next trial."""
        self.planner.route_to(destination)
        self.current_state = None
        self.positive_reward_earned = 0
        self.negative_reward_earned = 0
        self.num_resets += 1

    def update(self, t, debug=False):
        self.current_state = self.observe_current_state()
        action = self.select_next_action(debug)
        reward = self.env.act(self, action)
        self.do_reward_bookkeeping(reward)

        # Calling act() causes location to change if a valid move was made
        if not self.is_at_destination and self.learning:
            new_state = self.observe_current_state()

            # Learn policy based on state, action, reward via Q-Learning update
            # Equation 21.8 in Artificial Intelligence: A Modern Approach, 2e
            old_q = self.q_map[self.current_state][action]
            best_future_q = max(self.q_map[new_state].itervalues())
            new_q = self.alpha * (reward + self.gamma * best_future_q - old_q)
            new_q += old_q
            self.q_map[self.current_state][action] = new_q

        if debug:
            if self.learning:
                print "Current state: {}".format(self.current_state)
                print "Old Q for action {}: {}".format(action, old_q)
                print "Reward received: {}".format(reward)
                print "New Q for action {}: {}".format(action, new_q)
            else:
                print "Not learning; no update made"
            print "Deadline = {}\n".format(self.env.get_deadline(self))

    # Formatting
    def __str__(self):
        s = "LearningAgent: learning={}, alpha={}, gamma={}, boost={}, num_trials={}"
        return s.format(self.learning, self.alpha, self.gamma, self.q_boost,
                        self.num_trials)

    def format_q_map(self):
        output = []
        for state, actions in self.q_map.iteritems():
            output.append(str(state))
            for action, q_value in actions.iteritems():
                output.append("\t{}: {:.2f}".format(action, q_value))
        return "\n".join(output)

    # Helper methods
    def make_initial_q_map(self, strategy, q_boost):
        q_map = dict()
        for state in self.generate_all_agentstates():
            if strategy == weighted_q_average:
                q_map[state] = {a: 1.0 for a in self.env.valid_actions}
            else:
                q_map[state] = {a: random.random() for a in self.env.valid_actions}

        if q_boost:
            for state, q_values in q_map.iteritems():
                for action in self.env.valid_actions:
                    if state.next_waypoint == action:
                        q_map[state][action] += q_boost
        return q_map

    def do_reward_bookkeeping(self, reward):
        if reward >= 0:
            self.positive_reward_earned += reward
        else:
            self.negative_reward_earned += reward

    def observe_current_state(self):
        """
        Look around the Environment, gather needed info, and return an
        AgentState that captures what you see.
        """
        light = self.env.sense(self)['light']
        next_waypoint = self.planner.next_waypoint()
        return AgentState(light, next_waypoint)

    def select_next_action(self, debug=False):
        """
        Use self.current_state, self.strategy, and self.num_trials to choose
        next action.
        """
        q_values_current_state = self.q_map[self.current_state]
        if debug:
            print "Action choices:"
            print q_values_current_state
            print "Selected action: {}".format(action)
        return self.strategy(q_values_current_state, self.num_trials)

    def generate_all_agentstates(self):
        lights = ['green', 'red']   # as returned by Environment.sense
        waypoints = [a for a in self.env.valid_actions if a]
        for light, next_waypoint in product(lights, waypoints):
            yield AgentState(light=light, next_waypoint=next_waypoint)

    def stop_learning(self):
        self.learning = False

    def start_learning(self):
        self.learning = True

    # Info properties
    @property
    def agent_info(self):
        info = {
            'q_boost': self.q_boost,
            'alpha': self.alpha,
            'gamma': self.gamma,
            'strategy': self.strategy.__name__,
            'q_map': self.q_map,
            'num_resets': self.num_resets
        }
        return info

    @property
    def net_rewards(self):
        return self.positive_reward_earned - self.negative_reward_earned

    @property
    def is_at_destination(self):
        return self.planner.next_waypoint() is None

    @property
    def num_trials(self):
        return self.num_resets


# Solutions to various questions asked in the assignment
def q1_random_action():
    agent_params = {'strategy': explorer}
    return run_with_params(agent_params, False)


def q2_max_q_value():
    agent_params = {'strategy': exploiter, 'q_boost': 1}
    return run_with_params(agent_params, True, False)
