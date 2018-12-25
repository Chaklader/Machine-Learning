from random import randint, shuffle
from itertools import izip
import numpy as np

def genpop(n, low, high):
    return [randint(low, high) for _ in xrange(n)]

def shuffled(iterable):
    lst = list(iterable)
    shuffle(lst)
    return lst

def marry(n, low, high, datings=1000):
    males, females = genpop(n, low, high), genpop(n, low, high)
    for dating in xrange(datings):
        males, females = zip(*((male, female) for male, female in
            izip(shuffled(males), shuffled(females)) if female >= male))
    return (n - len(males)) / float(n)

print np.average([marry(1000, 0, 200) for _ in xrange(100)])