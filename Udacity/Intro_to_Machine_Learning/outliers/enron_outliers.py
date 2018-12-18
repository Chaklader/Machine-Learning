#!/usr/bin/python

import pickle
import sys
import matplotlib.pyplot as plt
from pprint import pprint


sys.path.append("../tools/")
from feature_format import featureFormat, targetFeatureSplit


### read in data dictionary, convert to numpy array
data_dict = pickle.load( open("../final_project/final_project_dataset.pkl", "r"))
features = ["salary", "bonus"]

# remove the 'TOTAL' from the dataset 
# --------------------------------- 
data_dict.pop("TOTAL",0)

data = featureFormat(data_dict, features)

# your code below
for point in data:
    salary = point[0]
    bonus = point[1]
    plt.scatter( salary, bonus )

#  uncomment to visualize 
#  ----------------------

plt.xlabel("salary")
plt.ylabel("bonus")
plt.show()


import numpy
numpy.amax(data)

# Check for Outliers
# {k: v for k, v in data_dict.items() if v['bonus'] != 'NaN' and v['bonus'] > 4000000}


# from pprint import pprint
# outliers = []

# for key in data_dict:
#     val = data_dict[key]['salary']
#     if val == 'NaN':
#         continue
#     outliers.append((key,int(val)))

# pprint(sorted(outliers,key=lambda x:x[1],reverse=True)[:2])


# To Find outlier
max =  0

#  what's the dictionary key of the biggest enron outliers ? 'TOTAL'
for key, value in data_dict.items():

	if( key !=  'TOTAL' and value['salary'] != 'NaN' and value['salary'] > max):
		max =  value['salary']
		print key, " ", max, " ", value['bonus'], " ", max + value['bonus']




# SKILLING JEFFREY K, LAY KENNETH L
#  --------------------------------

# biggest = 0
# for key, value in data_dict.items():
#     if value['bonus'] > biggest:
#         biggest = value['bonus']
#         print key 




