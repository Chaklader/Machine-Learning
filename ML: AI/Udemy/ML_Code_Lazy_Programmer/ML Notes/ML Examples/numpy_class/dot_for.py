

# >>> x = np.array([1, 2, 3, 4])
# >>> np.sum(x)
# 10
# >>> x.sum()
# 10
# ../../_images/reductions.png
# Sum by rows and by columns:
# >>>
# >>> x = np.array([[1, 1], [2, 2]])
# >>> x
# array([[1, 1],
#        [2, 2]])
# >>> x.sum(axis=0)   # columns (first dimension)
# array([3, 3])
# >>> x[:, 0].sum(), x[:, 1].sum()
# (3, 3)
# >>> x.sum(axis=1)   # rows (second dimension)
# array([2, 4])
# >>> x[0, :].sum(), x[1, :].sum()
# (2, 4)

import numpy as np
from datetime import datetime

a = np.random.randn(100)
b = np.random.randn(100)
T = 100000

def slow_dot_product(a, b):
	result = 0
	for e, f in zip(a, b):
		result += e*f
	return result

t0 = datetime.now()
for t in xrange(T):
	slow_dot_product(a, b)
dt1 = datetime.now() - t0

t0 = datetime.now()
for t in xrange(T):
	a.dot(b)
dt2 = datetime.now() - t0

print "dt1 / dt2:", dt1.total_seconds() / dt2.total_seconds()