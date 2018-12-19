#!/usr/bin/python

import sys
import pickle
import matplotlib.pyplot as plt
import pylab as pl

sys.path.append("../tools/")

from feature_format import featureFormat, targetFeatureSplit
from tester import test_classifier, dump_classifier_and_data


### Task 1: Select what features you'll use.
### features_list is a list of strings, each of which is a feature name.
### The first feature must be "poi".

features_list = ['poi','salary','bonus','total_payments','total_stock_value',
                'to_messages','from_poi_to_this_person',
                'from_messages','from_this_person_to_poi',
                'long_term_incentive'] # You will need to use more features

### Load the dictionary containing the dataset
data_dict = pickle.load(open("final_project_dataset.pkl", "r") )


### Task 2: Remove outliers
data_dict.pop( 'TOTAL', 0 )

### Task 3: Create new feature(s)
### Store to my_dataset for easy export below.
my_dataset = data_dict


# Create features fraction of emails that is from or to POI
for key in data_dict:

    if data_dict[key]['from_this_person_to_poi']=='NaN' or data_dict[key]['from_messages']=='NaN':
      data_dict[key]['from_ratio'] = 0
    else:  
      data_dict[key]['from_ratio'] = (1.0*data_dict[key]['from_this_person_to_poi']/data_dict[key]['from_messages'])   

    if (data_dict[key]['from_poi_to_this_person']=='NaN') or (data_dict[key]['to_messages']=='NaN'):
      data_dict[key]['to_ratio'] = 0
    else:  
      data_dict[key]['to_ratio'] = (1.0*data_dict[key]['from_poi_to_this_person']/data_dict[key]['to_messages'])   




# Create square root of financial features
import math
for key in data_dict:

    if (data_dict[key]['salary']=='NaN'):
      data_dict[key]['sqrt_salary'] = 0
    else:  
      data_dict[key]['sqrt_salary'] = math.sqrt(data_dict[key]['salary'])

    if (data_dict[key]['bonus']=='NaN'):        
      data_dict[key]['sqrt_bonus'] = 0
    else:  
      data_dict[key]['sqrt_bonus'] = math.sqrt(data_dict[key]['bonus'])

    if (data_dict[key]['total_stock_value']=='NaN') or (data_dict[key]['total_stock_value']<0):        
      data_dict[key]['sqrt_total_stock_value'] = 0
    else:  
      data_dict[key]['sqrt_total_stock_value'] = math.sqrt(data_dict[key]['total_stock_value'])

    if (data_dict[key]['long_term_incentive']=='NaN'):        
      data_dict[key]['sqrt_long_term_incentive'] = 0
    else:  
      data_dict[key]['sqrt_long_term_incentive'] = math.sqrt(data_dict[key]['long_term_incentive'])
    
    if (data_dict[key]['bonus']=='NaN') or data_dict[key]['salary']=='NaN' : 
      data_dict[key]['bonus_salary_ratio']=0
    else:
      data_dict[key]['bonus_salary_ratio']=data_dict[key]['bonus']/data_dict[key]['salary']

      
### Extract features and labels from dataset for local testing
features_list = ['poi','salary','bonus','from_ratio','to_ratio',
                 'sqrt_total_stock_value','sqrt_long_term_incentive',
                 'sqrt_salary','sqrt_bonus','bonus_salary_ratio']

data = featureFormat(my_dataset, features_list, sort_keys = True)
labels, features = targetFeatureSplit(data)


# scatter plot of features 
poi = list(data[:,0])
salary = list(data[:,1])
bonus = list(data[:,2])
from_ratio = list(data[:,3])
to_ratio = list(data[:,4])
total_stock_value = list(data[:,5])
long_term_incentive = list(data[:,6])
sqrt_salary = list(data[:,7])
sqrt_bonus = list(data[:,8])
bonus_salary_ratio = list(data[:,9])


plt.scatter(salary, bonus, s=100, c=poi)
plt.title('Salary vs bonus after removing outlier')
plt.ylabel('bonus ')
plt.xlabel('salary')
plt.show()


plt.scatter(sqrt_salary, sqrt_bonus, s=100, c=poi)
plt.title('Square root of salary and bonus')
plt.ylabel('square root of bonus ')
plt.xlabel('square root of salary')
plt.show()


plt.scatter(total_stock_value, long_term_incentive, s=100, c=poi)
plt.title('Square root of total stock value and long term incentive')
plt.ylabel('square root of total stock value ')
plt.xlabel('square root of long term incentive')
plt.show()


plt.scatter(from_ratio, to_ratio, s=100, c=poi) 
plt.title('proportion of from and to emails related to POI')
plt.ylabel('proportion of to emails related to POI ')
plt.xlabel('proportion of from emails related to POI')
plt.show()


plt.scatter(salary, bonus_salary_ratio, s=100, c=poi)
plt.title('bonus to salary ratio')
plt.ylabel('bonus to salary ratio ')
plt.xlabel('salary')
plt.show()


### Task 4: Try a varity of classifiers
features_list = ['poi','from_ratio','to_ratio',
                 'sqrt_total_stock_value','sqrt_long_term_incentive',
                 'sqrt_salary','sqrt_bonus','bonus_salary_ratio']


from sklearn.naive_bayes import GaussianNB
from sklearn.ensemble import RandomForestClassifier
from sklearn import tree

### Please name your classifier clf for easy export below.
### Note that if you want to do PCA or other multi-stage operations,
### you'll need to use Pipelines. For more info:
### http://scikit-learn.org/stable/modules/pipeline.html

from sklearn.pipeline import Pipeline
from sklearn.decomposition import PCA

# PCA for decision tree
estimators = [('reduce_dim', PCA(n_components=4)), ('tree', tree.DecisionTreeClassifier())]

# PCA for random forest
# estimators = [('reduce_dim', PCA(n_components=3)), ('rf',RandomForestClassifier() )]
clf = Pipeline(estimators)


### Task 5: Tune your classifier to achieve better than .3 precision and recall 
### using our testing script.
### Because of the small size of the dataset, the script uses stratified
### shuffle split cross validation. For more info: 
### http://scikit-learn.org/stable/modules/generated/sklearn.cross_validation.StratifiedShuffleSplit.html
# tree

from sklearn import grid_search

# Parmaters of Decision Trees
# ========================================================================================
# min_samples_split : int, float, optional (default=2)
# The minimum number of samples required to split an internal node:
# If int, then consider min_samples_split as the minimum number.
# If float, then min_samples_split is a percentage and ceil(min_samples_split * n_samples) 
# are the minimum number of samples for each split.


# min_samples_leaf : int, float, optional (default=1)
# The minimum number of samples required to be at a leaf node:
# If int, then consider min_samples_leaf as the minimum number.
# If float, then min_samples_leaf is a percentage and ceil(min_samples_leaf * n_samples) 
# are the minimum number of samples for each node.

# ========================================================================================

parameters = {'min_samples_leaf':[1,2,3,4,5], 'min_samples_split':[2,3,4,5]}

# =============
# Random Forest 
# =============

# Random forests or random decision forests are an ensemble learning method for classification, 
# regression and other tasks, that operate by constructing a multitude of decision trees at 
# training time and outputting the class that is the mode of the classes (classification) or 
# mean prediction (regression) of the individual trees. Random decision forests correct for 
# decision trees' habit of overfitting to their training set

# n_estimators : integer, optional (default=10)
# The number of trees in the forest.
# parmaters of random forest
# parameters = {'min_samples_leaf':[1,2,3,4,5], 'min_samples_split':[2,3,4,5],
#              'n_estimators':[5,10,20,30]}

# ========================================================================================

mclf = tree.DecisionTreeClassifier()


# mclf = RandomForestClassifier()
clf = grid_search.GridSearchCV(mclf, parameters)
clf = clf.fit(features, labels)
clf = clf.best_estimator_


# clf = GaussianNB() 

# NOTE, the result from GridSearch is a little different 
# it does not give the best result in terms of precision and recall
# here i find this set parameters are better in terms of precision and recall
clf = tree.DecisionTreeClassifier(min_samples_leaf=1,min_samples_split=2)
#clf = RandomForestClassifier()

test_classifier(clf, my_dataset, features_list)
### Dump your classifier, dataset, and features_list so 
### anyone can run/check your results.

dump_classifier_and_data(clf, my_dataset, features_list)
