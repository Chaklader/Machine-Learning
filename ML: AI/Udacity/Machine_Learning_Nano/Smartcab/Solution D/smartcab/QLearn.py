import random
import os
from environment import Agent, Environment
from planner import RoutePlanner
from simulator import Simulator

script_dir = os.path.dirname(__file__)

path = os.path.join(script_dir, '../report/output_qlearning.txt')
if not os.path.exists('file'):
    open(path, 'w').close() 

class QTable(object):
    def __init__(self):
        self.Q = dict()

    def get(self, state, action):
        key = (state, action)
        return self.Q.get(key, None)

    def set(self, state, action, q):
        key = (state, action)
        self.Q[key] = q

    def report(self):
        for k, v in self.Q.items():
            print k, v

class QLearn(Agent):
    def __init__(self, epsilon=.1, alpha=.5, gamma=.9):
        self.Q = QTable()       # Q(s, a)
        self.epsilon = epsilon  # probability of doing random move
        self.alpha = alpha      # learning rate
        self.gamma = gamma      # memory / discount factor of max Q(s',a')
        self.possible_actions = Environment.valid_actions
        with open(path, 'a') as file:
            file.write("\n*** parameters: epsilon: {}, alpha {}, gamma: {}\n".format(self.epsilon, self.alpha, self.gamma))
            file.write("************************************************\n")

    def Q_move(self, state):
        if random.random() < self.epsilon: # exploration action ==> random move
            action = random.choice(self.possible_actions)
        else: # base the decision on q
            q = [self.Q.get(state, a) for a in self.possible_actions]
            max_q = max(q)
            # we have identical max q from Q, which one to choose?
            if q.count(max_q) > 1: 
                # pick an action randomly from all max
                best_actions = [i for i in range(len(self.possible_actions)) if q[i] == max_q]                       
                action_idx = random.choice(best_actions)

            else:
                action_idx = q.index(max_q)
            action = self.possible_actions[action_idx]
        return action
    
    def Q_learn(self, state, action, reward, new_q):       
        q = self.Q.get(state, action)
        if q is None:
            q = reward
        else:
            q += self.alpha * new_q

        self.Q.set(state, action, q)

    def Q_post(self, state, action, next_state, reward):
        # Qval(State,action) = currentQval(State,action) - alpha*(newQval - currenQval(State,action)) 
        q = [self.Q.get(next_state, a) for a in self.possible_actions]
        future_rewards = max(q)         
        if future_rewards is None:
            future_rewards = 0.0
        self.Q_learn(state, action, reward, reward - self.gamma * future_rewards)  
        self.Q.report() ## Debug

class QLearningAgent(Agent):
    """An agent that learns to drive in the smartcab world by using Q-Learning"""

    def __init__(self, env):
        super(QLearningAgent, self).__init__(env)  # sets self.env = env, state = None, next_waypoint = None, and a default color
        self.color = 'red'  # override color
        self.planner = RoutePlanner(self.env, self)  # simple route planner to get next_waypoint
        self.possible_actions= Environment.valid_actions
        self.ai = QLearn(epsilon=.05, alpha=0.1, gamma=0.9)        

    def reset(self, destination=None):
        self.planner.route_to(destination)      

    def update(self, t):
        # Gather inputs
        self.next_waypoint = self.planner.next_waypoint()  # from route planner, also displayed by simulator
        inputs = self.env.sense(self) 
        inputs = inputs.items()
        deadline = self.env.get_deadline(self)

        self.state = (inputs[0],inputs[1],inputs[3],self.next_waypoint)
        
        action = self.ai.Q_move(self.state)
        
        # Execute action and get reward
        reward = self.env.act(self, action)

        inputs2 = self.env.sense(self) 
        inputs2 = inputs2.items()
        next_state = (inputs2[0],inputs2[1],inputs2[3],self.next_waypoint)

        self.ai.Q_post(self.state, action, next_state, reward)

        print "LearningAgent.update(): deadline = {}, inputs = {}, action = {}, reward = {}".format(deadline, inputs, action, reward)  # [debug]

def run():
    """Run the agent for a finite number of trials."""

    # Set up environment and agent
    e = Environment()  # create environment (also adds some dummy traffic)
    a = e.create_agent(QLearningAgent)  # create agent
    e.set_primary_agent(a, enforce_deadline=True)  # set agent to track

    # Now simulate it
    sim = Simulator(e, update_delay=.0001)  # reduce update_delay to speed up simulation
    sim.run(n_trials=100)  # press Esc or close pygame window to quit


if __name__ == '__main__':
    run()