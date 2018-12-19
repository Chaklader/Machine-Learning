#!/usr/bin/python 

""" 
    Skeleton code for k-means clustering mini-project.
"""

import pickle
import numpy
import matplotlib.pyplot as plt
import sys


sys.path.append("../tools/")
from feature_format import featureFormat, targetFeatureSplit


def Draw(pred, features, poi, mark_poi=False, name="image.png", f1_name="feature 1", f2_name="feature 2"):

    """ some plotting code designed to help you visualize your clusters """

    ### plot each cluster with a different color--add more colors for
    ### drawing more than five clusters

    colors = ["b", "c", "k", "m", "g"]

    for ii, pp in enumerate(pred):
        plt.scatter(features[ii][0], features[ii][1], color = colors[pred[ii]])

    ### if you like, place red stars over points that are POIs (just for funsies)
    if mark_poi:
        for ii, pp in enumerate(pred):
            if poi[ii]:
                plt.scatter(features[ii][0], features[ii][1], color="r", marker="*")

    plt.xlabel(f1_name)
    plt.ylabel(f2_name)
    plt.savefig(name)
    plt.show()


### load in the dict of dicts containing all the data on each person in the dataset
data_dict = pickle.load( open("../final_project/final_project_dataset.pkl", "r"))
### there's an outlier--remove it! 
data_dict.pop("TOTAL", 0)


### the input features we want to use 
### can be any key in the person-level dictionary (salary, director_fees, etc.) 
feature_1 = "salary"
feature_2 = "exercised_stock_options"
feature_3 = "total_payments"

poi  = "poi"

features_list = [poi, feature_1, feature_2, feature_3]
data = featureFormat(data_dict, features_list)

# return target, features
poi, finance_features = targetFeatureSplit(data)



### in the "clustering with 3 features" part of the mini-project,
### you'll want to change this line to 
### for f1, f2, _ in finance_features:
### (as it's currently written, the line below assumes 2 features)
# for f1, f2, f3 in finance_features:
#     plt.scatter(f1, f2, f3)

# plt.show()

### cluster here; create predictions of the cluster labels
### for the data and store them to a list called pred

from sklearn.cluster import KMeans
features_list = ["poi", feature_1, feature_2]
data2 = featureFormat(data_dict, features_list )
poi, finance_features = targetFeatureSplit(data2)

clf = KMeans(n_clusters=2)
pred = clf.fit_predict( finance_features )
# Draw(pred, finance_features, poi, name="clusters_before_scaling.pdf", f1_name=feature_1, f2_name=feature_2)




### rename the "name" parameter when you change the number of features
### so that the figure gets saved to a different file
try:
    Draw(pred, finance_features, poi, mark_poi = False, name="clusters.pdf", f1_name = feature_1,\
     f2_name=feature_2)
except NameError:
    print "no predictions object named pred found, no clusters to plot"




# Find exercised_stock_options
import operator
stock = {k: v['exercised_stock_options'] for k, v in data_dict.items() if v['exercised_stock_options'] != 'NaN'}

## Maximum exercised_stock_options
#  -------------------------------
# maxval = max(stock.iteritems(), key=operator.itemgetter(1))[1]

try:
    maxval = max((kv for kv in stock.iteritems() if kv[1] != 'NaN'),\
                key=operator.itemgetter(1))

except ValueError:
    # no stock at all
    maxval = None

max_stock = {k: v for k,v in stock.items() if v==maxval}
print  "max stock = ", max_stock

# Minimum exercised_stock_options
minval = min(stock.iteritems(), key=operator.itemgetter(1))[1]
min_stock = {k: v for k,v in stock.items() if v==minval}
print  "min stock = ", min_stock


# ex_stok = []
# for users in data_dict:
#     val = data_dict[users]["exercised_stock_options"]
#     if val == 'NaN':
#         continue
#     ex_stok.append(val)
# print max(ex_stok)
# print min(ex_stok)



# Find salary
salary = {k: v['salary'] for k, v in data_dict.items() if v['salary'] != 'NaN'}


# Maximum salary
maxval = max(salary.iteritems(), key=operator.itemgetter(1))[1]
max_salary = {k: v for k,v in salary.items() if v==maxval}
print  "max salary = ", max_salary


# Minimum salary
minval = min(salary.iteritems(), key=operator.itemgetter(1))[1]
min_salary = {k: v for k,v in salary.items() if v==minval}
print  "min salary = ", min_salary


# Salary
# salary = []
# for users in data_dict:
#     val = data_dict[users]["salary"]
#     if val == 'NaN':
#         continue
#     salary.append(val)
    
# print max(salary)
# print min(salary)

#{k: v['salary'] for k, v in data_dict.items() if v['salary'] != 'NaN' and v['salary'] < 4000}


exercised_stock_options = {k: v['exercised_stock_options'] for k, v in data_dict.items() if v['exercised_stock_options'] != 'NaN'}

# Maximum salary
maxval = max(exercised_stock_options.iteritems(), key=operator.itemgetter(1))[1]
max_exercised_stock_options = {k: v for k,v in exercised_stock_options.items() if v==maxval}
print  "max exercised stock options = ", max_exercised_stock_options


# Minimum salary
minval = min(max_exercised_stock_options.iteritems(), key=operator.itemgetter(1))[1]
min_exercised_stock_options = {k: v for k,v in max_exercised_stock_options.items() if v==minval}
print  "min exercised stock options = ", min_exercised_stock_options


from sklearn.preprocessing import MinMaxScaler
scaler = MinMaxScaler()

# the MaxMinScalar needs float to work 
# ------------------------------------
# stocks = numpy.array([[float(min_exercised_stock_options)], [float(1000000)], [float(max_exercised_stock_options)]])
salaries = numpy.array([[float(min_salary)], [200000.], [float(max_salary)]]) 


# stockes_scaled =  scaler.fit_transform(stocks)
salaries_scaled = scaler.fit_transform(salaries)


# print "salaries scaled = ", salaries_scaled
print "stockes scaled = ", stockes_scaled














