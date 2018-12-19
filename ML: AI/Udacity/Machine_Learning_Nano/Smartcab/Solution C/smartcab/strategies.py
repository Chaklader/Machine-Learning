"""
Strategies a LearningAgent can use when deciding whether to explore or exploit,
given the Q-values associated with its current state and the trial it's on.

state_q_values map the currently available actions to their Q values.
"""

from numpy.random import choice
from math import exp, log
import random

def explorer(state_q_values, trial):
    """
    An explorer always returns a random action choice, ignoring Q values.
    The trial is also ignored.
    """
    return choice(state_q_values.keys())


def exploiter(state_q_values, trial):
    """
    An exploiter always returns the action with the largest Q value.
    The trial is also ignored.
    """
    return max(state_q_values, key=state_q_values.get)


def decay_exponential(state_q_values, trial, num_trials=100):
    """
    Explore with probability p and exploit with probability (1-p),
    where p(trial) = exp(-trial / 0.3 * num_trials).

    The 0.3 was picked to decay from 1 to 0 over ~100 trials at a reasonable rate:
    - On trial 0,  we explore w.p. 1
    - On trial 1,  we explore w.p. 0.967
    - On trial 10, we explore w.p. 0.717
    - On trial 50, we explore w.p. 0.189
    - On trial 99, we explore w.p. 0.037
    """
    p = exp(-1.0 * trial / (num_trials * 0.3))
    if p >= random.random():
        return explorer(state_q_values, trial)
    else:
        return exploiter(state_q_values, trial)


def decay_linear(state_q_values, trial, num_trials=100):
    """
    Explore with probability p and exploit with probability (1-p),
    where p(trial) is a decreasing linear function of trial.

    - On trial 0,  we explore w.p. 1
    - On trial 10, we explore w.p. 0.9
    - On trial 50, we explore w.p. 0.5
    - On trial 99, we explore w.p. 0.01
    """
    p = 1 - (1.0 * trial) / num_trials
    if p >= random.random():   # if p < 0, then this never happens
        return explorer(state_q_values, trial)
    else:
        return exploiter(state_q_values, trial)


def decay_logarithmic(state_q_values, trial, num_trials=100):
    """
    Explore with probability p and exploit with probability (1-p),
    where p(trial) is a decreasing logarithmic function of trial.

    With 100 trials, the decay looks like:
    - On trial 0,  we explore w.p. 1
    - On trial 10, we explore w.p. 0.977
    - On trial 50, we explore w.p. 0.85
    - On trial 90, we explore w.p. 0.5
    - On trial 95, we explore w.p. 0.35
    - On trial 98, we explore w.p. 0.15
    """
    try:
        p = log(num_trials - trial, num_trials)
    except ValueError:
        p = 0.0

    if p >= random.random():
        return explorer(state_q_values, trial)
    else:
        return exploiter(state_q_values, trial)
