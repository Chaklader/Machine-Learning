import random
from environment import Agent, Environment
from planner import RoutePlanner
from simulator import Simulator

class LearningAgent(Agent):
    """An agent that learns to drive in the smartcab world."""

    def __init__(self, env):
        super(LearningAgent, self).__init__(env)  # sets self.env = env, state = None, next_waypoint = None, and a default color
        self.color = 'red'  # override color
        self.planner = RoutePlanner(self.env, self)  # simple route planner to get next_waypoint
        # TODO: Initialize any additional variables here
        ## Actions 
        self.A = ['forward', 'left', 'right',None] # all avaiable action
        self.trial = 0 # the number of trails
        # Inicialize Q table(light, oncoming, next_waypoint)
        self.Q = {}
        for i in ['green', 'red']:  # possible lights
          for j in [None, 'forward', 'left', 'right']:  # possible oncoming 
            for k in ['forward', 'left', 'right']:  ## possible next_waypoints
                    self.Q[(i,j,k)] = [1] * len(self.A)  ## linized Q talbe

    def reset(self, destination=None):
        self.planner.route_to(destination)
        # TODO: Prepare for a new trip; reset any variables here, if required

    def update(self, t):
        # Gather inputs
        self.next_waypoint = self.planner.next_waypoint()  # from route planner, also displayed by simulator
        inputs = self.env.sense(self)
        deadline = self.env.get_deadline(self)

        # TODO: Update state
        self.state = (inputs['light'],inputs['oncoming'], self.next_waypoint)
        #print "inputs"
        # TODO: Select action according to your policy
        #action = None
        #action = random.choice(self.env.valid_actions) # random action
        ## Find the max Q value for the current state
        max_Q = self.Q[self.state].index(max(self.Q[self.state]))

        ## assign action 
        p = random.randrange(0,5)
        epsilon = 1.5 # small probability to act randomly
        if p<epsilon:
            action = random.choice(self.env.valid_actions)
        else:
            action = self.A[max_Q]

        # Execute action and get reward
        reward = self.env.act(self, action)

        # TODO: Learn policy based on state, action, reward
        gamma = 0.2  ## discount factor for next states and actions
        #alpha = 0.5  ## learning rate, 0 no learn 1 full learn
        
        alp_tune =500 # tunning parameter
        alpha = 1/(1.1+self.trial/alp_tune) # decay learning rate
        self.trial = self.trial+1

        ## get the next state,action Q(s',a')
        next_inputs = self.env.sense(self)
        next_next_waypoint = self.planner.next_waypoint()
        next_state = (next_inputs['light'],next_inputs['oncoming'], next_next_waypoint)

        ## update Q table
        self.Q[self.state][self.A.index(action)] = \
            (1-alpha)*self.Q[self.state][self.A.index(action)] + \
            (alpha * (reward + gamma * max(self.Q[next_state])))

        #print "LearningAgent.update(): deadline = {}, inputs = {}, action = {}, reward = {}".format(deadline, inputs, action, reward)  # [debug]


def run():
    """Run the agent for a finite number of trials."""

    # Set up environment and agent
    e = Environment()  # create environment (also adds some dummy traffic)
    a = e.create_agent(LearningAgent)  # create agent
    #e.set_primary_agent(a, enforce_deadline=False)  # set agent to track
    e.set_primary_agent(a, enforce_deadline=True)
    # Now simulate it
    sim = Simulator(e, update_delay=0.000001)  # reduce update_delay to speed up simulation
    sim.run(n_trials=100)  # press Esc or close pygame window to quit
    
    ## print Q table
    for key in a.Q:
        print key,
        print ["%0.2f" % i for i in a.Q[key]]

if __name__ == '__main__':
    run()
