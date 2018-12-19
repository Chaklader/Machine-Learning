import random
from environment import Agent, Environment
from planner import RoutePlanner
from simulator import Simulator
import math
from collections import namedtuple
from QLearningAgent import QLearningAgent
import pprint


class LearningAgent(Agent):
    """An agent that learns to drive in the smartcab world."""

    def __init__(self, env):
        """
        initializes the environment variables
        input: env, initializes the environment variable for sensing

        working: also responsible for initializing the color of the car,
        initializing the route planner and the reward and previous action.
        """
        super(LearningAgent, self).__init__(env)  
        self.color = 'black'  
        self.planner = RoutePlanner(self.env, self)  # simple route planner to get next_waypoint
        self.previous_reward = 0
        self.previous_action = None

    def reset(self, destination=None):
        """
        reset values to start a new trial run
        """
        self.planner.route_to(destination)
        # TODO: Prepare for a new trip; reset any variables here, if required
        self.previous_reward = 0
        self.previous_action = None
        self.state = None

    def update(self, t):
        """
        Main update method that is responsible for updating the agent action.
        """
        # Gather inputs
        self.next_waypoint = self.planner.next_waypoint()  # from route planner, also displayed by simulator
        inputs = self.env.sense(self)
        deadline = self.env.get_deadline(self)

        # TODO: Update state
        ## currently using two states called random and initiated
        if(self.state == None):
            self.state = 'Random'
        #print 'environment state:'
        # {'light': 'green', 'oncoming': None, 'right': None, 'left': None}
        current_env_state = self.env.sense(self)
        action = None

        possible_actions = []
        if(current_env_state['light'] == 'red'):
            if(current_env_state['oncoming'] != 'left'):
                possible_actions = ['right', None]
        else:
            # traffic ligh is gree and now check for oncoming
            #if no oncoming 
            if(current_env_state['oncoming'] == 'forward'):
                possible_actions = [ 'forward','right']
            else:
                possible_actions = ['right','forward', 'left']
        
        # TODO: Select action according to your policy
        if possible_actions != [] and self.state == 'Random':
            action_int =  random.randint(0,len(possible_actions)-1)
            action = possible_actions[action_int]
        elif possible_actions != [] and self.state == 'Initiated':
            action = self.previous_action
            


        # Execute action and get reward
        reward = self.env.act(self, action)

        # TODO: Learn policy based on state, action, reward

        if(action != None):
            if(reward > self.previous_reward):
                self.state = 'Initiated'
                self.previous_action = action
                self.previous_reward = reward
            else:
                self.state = 'Random'
                self.previous_action = action
                self.previous_reward = reward

        print "LearningAgent.update(): deadline = {}, inputs = {}, action = {}, reward = {}".format(deadline, inputs, action, reward)  # [debug]


def allPossibleStates():
    states = ["next_waypoint","destination","location",
                "destination","light","oncoming","left","right","heading"]
    return states

def run():
    """Run the agent for a finite number of trials."""

    e = Environment()  # create environment (also adds some dummy traffic)
    a = e.create_agent(QLearningAgent)  # create agent
    e.set_primary_agent(a, enforce_deadline=True)  # set agent to track
        # Now simulate it
    sim = Simulator(e, update_delay=0.00001)  # reduce update_delay to speed up simulation
    sim.run(n_trials=100)  # press Esc or close pygame window to quit

    
if __name__ == '__main__':
    run()
