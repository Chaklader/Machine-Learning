import random
from environment import Agent, Environment
from planner import RoutePlanner
from simulator import Simulator
import math
from collections import namedtuple
import pprint
from scipy import constants as sc

class QLearningAgent(Agent):
    """An agent that learns to drive in the smartcab world using Q learning"""

    def __init__(self, env):
        super(QLearningAgent, self).__init__(env)  # sets self.env = env, state = None, next_waypoint = None, and a default color
        self.color = 'red'  # OverflowError(" error")ide color
        self.planner = RoutePlanner(self.env, self)  # simple route planner to get next_waypoint
        ##initialize q table here
        self.qDict = dict()
        self.alpha    = 0.9
        self.epsilon  = 0.0 ##initial probability of flipping the coin
        self.gamma    = 0.35
        self.discount = self.gamma
        self.previous_state = None
        self.state = None
        self.previous_action = None
        self.deadline = self.env.get_deadline(self)       
        self.previous_reward = None
        self.cumulativeRewards = 0


    def flipCoin(self, p ):
        r = random.random()
        return r < p

    def reset(self, destination=None):
        """
        resets the current values of the agent
        """
        self.planner.route_to(destination)
        self.previous_state = None
        self.state = None
        self.previous_action = None
        self.epsilon = 0.0
        self.cumulativeRewards = 0

    def getLegalActions(self, state):
        """
        returns the legal action from the current state
        """
        return ['forward', 'left', 'right', None]

    ##gets the q value for a particulat state and action
    def getQValue(self, state, action):
        """
        input: (state,action)
        output: Q value for the (state,action)

        returns 0 if the value is not present in the dictionary.
        """
        return self.qDict.get((state, action), 20.0)  ##return the value from the qDict, default to 0 if the key isnt in the dict

    def getValue(self, state):
        """
         Returns max_action Q(state,action)

         where the max is over legal actions.  Note that if
         there are no legal actions, which is the case at the
         terminal state, you should return a value of 0.0.
        """
        legalActions = self.getLegalActions(state) 
        bestQValue = - 999999999
        
        for action in legalActions:
            #for each action check if the q value for the action is greater than minus infinity
            if(self.getQValue(state, action) > bestQValue):
                bestQValue = self.getQValue(state, action)

        return bestQValue

    def getPolicy(self, state):
        """
        Compute the best action to take in a state.

        input: state
        output: best possible action(policy maps states to action)

        Working:
        From all the legal actions, return the action that has the bestQvalue.
        if two actions are tied, flip a coin and choose randomly between the two.

        """
        legalActions = self.getLegalActions(state)  
        bestAction = None
        bestQValue = - 999999999
        for action in legalActions:
            if(self.getQValue(state, action) > bestQValue):
                bestQValue = self.getQValue(state, action)
                bestAction = action
            if(self.getQValue(state, action) == bestQValue):
                if(self.flipCoin(.5)):
                    bestQValue = self.getQValue(state, action)
                    bestAction = action
        return bestAction

    def makeState(self, state):
        """
        This function makes a state and returns 

        input: State
        ouput: Named State tuple

        This is useful for creating the q dictionary.
        """
        ## harnesss 'destination': (4, 5), 'deadline': 20, 'location': (7, 1), 'heading': (0, 1)
        State = namedtuple("State", ["light","next_waypoint"])
        return State(light = state['light'],
                        next_waypoint = self.planner.next_waypoint())
 

    def update(self, t):
        """
        This is the overridden mehtod that basically peforms the necessary update
        """
        
        self.next_waypoint = self.planner.next_waypoint()  # from route planner, also displayed by simulator

        ## this is my current state
        self.state = self.makeState(self.env.sense(self))

        ##get the current best action based on q table
        action = self.getAction(self.state)

        ##perform the action and now get the reward
        reward = self.env.act(self, action)

        ## in case of initial configuration don't update the q table, else update q table
        if self.previous_reward!= None:
            self.updateQTable(self.previous_state,self.previous_action,self.state,self.previous_reward)

        # store the previous action and state so that we can update the q table on the next iteration
        self.previous_action = action
        self.previous_state = self.state
        self.previous_reward = reward
        self.cumulativeRewards += reward
        # pretty print q table (optional)



    def getAction(self, state):
        """
        Compute the action to take in the current state. 

        Working:
        epsilon of the time, choose a random action from all legal actions,
        else choose the action given by the policy

        TODO:
        implement a dealine specific epsilon. Exploit when time limit is reached
        """
    # Pick Action
        legalActions = self.getLegalActions(state)  
        action = None
        print legalActions
        if (self.flipCoin(self.epsilon)):
            print "random choice"
            action = random.choice(legalActions)
        else:
            print "policy choice"
            action = self.getPolicy(state)
        return action

    def updateQTable(self, state, action, nextState, reward):
        """
         The parent class calls this to observe a
         state = action => nextState and reward transition.
         You should do your Q-Value update here
     
         NOTE: You should never call this function,
         it will be called on your behalf
        """
    
        if((state, action) not in self.qDict): 
            self.qDict[(state, action)] = 20.0
        else:
            self.qDict[(state, action)] = self.qDict[(state, action)] + self.alpha*(reward + self.discount*self.getValue(nextState) - self.qDict[(state, action)]) ##set the previous state's qValue to itself plus alpha*(reward + gamma*value of next state - old q value)
