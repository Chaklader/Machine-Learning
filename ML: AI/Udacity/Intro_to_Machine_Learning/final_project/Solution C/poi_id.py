#!/usr/bin/python

###Preparation

import sys
import pickle
import numpy
import pandas
import sklearn
from time import time
from copy import copy


#import ggplot
#from ggplot import *
import matplotlib
%matplotlib inline

import warnings
warnings.filterwarnings('ignore')

sys.path.append("../tools/")

from feature_format import featureFormat, targetFeatureSplit
from tester import test_classifier, dump_classifier_and_data
import enron 
import evaluate


numpy.random.seed(42)


## Create features list
features_list = ['poi', 'salary', 'to_messages', 'deferral_payments', 'total_payments', 
                 'loan_advances', 'bonus', 'restricted_stock_deferred', 
                 'deferred_income', 'total_stock_value', 'expenses', 'from_poi_to_this_person', 
                 'exercised_stock_options', 'from_messages', 'other', 'from_this_person_to_poi', 
                 'long_term_incentive', 'shared_receipt_with_poi', 'restricted_stock', 'director_fees'] 


### Load the dictionary containing the dataset
enron_data = pickle.load(open("final_project_dataset.pkl", "r") )


## Load POI names file
fpoi = open("poi_names.txt", "r")

# Print available information for Jeffrey Skilling
print enron_data["SKILLING JEFFREY K"]

#People in the dataset
people = len(enron_data)
print "There are " + str(people) + " people in the dataset."

#Features in the dataset
features = len(enron_data['SKILLING JEFFREY K'])
print "There are " + str(features) + " features in the dataset."

#poi's in the dataset
def poi_counter(file):
    count = 0 
    for person in file:
        if file[person]['poi'] == True:
            count += 1
    print "There are " + str(count) + " poi's in the dataset."

poi_counter(enron_data)


#Total Poi
fpoi = open("poi_names.txt", "r")
rfile = fpoi.readlines()

# first 2 lines are blank/ unnecessary info   
poi = len(rfile[2:])
print "There were " + str(poi) + " poi's total."



# Outliers
# Detect and remove outliers
features = ["bonus", "salary"]
data = featureFormat(enron_data, features)


### your code below
print data.max()
for point in data:
    bonus = point[0]
    salary = point[1]
    matplotlib.pyplot.scatter( bonus, salary )

matplotlib.pyplot.xlabel("bonus")
matplotlib.pyplot.ylabel("salary")
matplotlib.pyplot.show()

## check what is this outlier
from pprint import pprint
bonus_outliers = []

for key in enron_data:
    val = enron_data[key]['bonus']
    if val == 'NaN':
        continue
    bonus_outliers.append((key,int(val)))

pprint(sorted(bonus_outliers,key=lambda x:x[1],reverse=True)[:2])


salary_outliers = []
for key in enron_data:
    val = enron_data[key]['salary']
    if val == 'NaN':
        continue
    salary_outliers.append((key,int(val)))

pprint(sorted(salary_outliers,key=lambda x:x[1],reverse=True)[:2])


###TOTAL column as the major outlier in this dataset, Looking the the XLS we found it is the EXCEL artifact and should be removed. 
###Another outlier is also determined, THE TRAVEL AGENCY IN THE PARK this record did not represent an individual. Both of these should be removed.

features = ["salary", "bonus"]

# remove both outliers 
enron_data.pop('TOTAL',0)
enron_data.pop('THE TRAVEL AGENCY IN THE PARK',0)

my_dataset = copy(enron_data)
my_feature_list = copy(features_list)
data = featureFormat(enron_data, features)

### your code below
print data.max()
for point in data:
    salary = point[0]
    bonus = point[1]
    matplotlib.pyplot.scatter( salary, bonus )

matplotlib.pyplot.xlabel("salary")
matplotlib.pyplot.ylabel("bonus")
matplotlib.pyplot.show()

 
### since 'from_poi_to_this_person' and 'from_this_person_to_poi' are very important features too, 
### we shoudl investigate those w.r.t. outliers and remove any outliers.
features = ["from_this_person_to_poi", "from_poi_to_this_person"]
data = featureFormat(enron_data, features)


### your code below
print data.max()
for point in data:
    from_this_person_to_poi = point[0]
    from_poi_to_this_person = point[1]
    matplotlib.pyplot.scatter( from_this_person_to_poi, from_poi_to_this_person )


matplotlib.pyplot.xlabel("from_this_person_to_poi")
matplotlib.pyplot.ylabel("from_poi_to_this_person")
matplotlib.pyplot.show()

to_poi_outliers = []
for key in enron_data:
    val = enron_data[key]['from_this_person_to_poi']
    if val == 'NaN':
        continue
    to_poi_outliers.append((key,int(val)))

pprint(sorted(to_poi_outliers,key=lambda x:x[1],reverse=True)[:2])

from_poi_outliers = []
for key in enron_data:
    val = enron_data[key]['from_poi_to_this_person']
    if val == 'NaN':
        continue
    from_poi_outliers.append((key,int(val)))

pprint(sorted(from_poi_outliers,key=lambda x:x[1],reverse=True)[:2])

### These are real people and I am going to keep them in the dataset. 
### I'll only be removing 'TOTAL' and 'THE TRAVEL AGENCY IN THE PARK' for my final file

# Load data into Pandas
# ---------------------
df = pandas.DataFrame.from_records(list(enron_data.values()))
persons = pandas.Series(list(enron_data.keys()))

#View of Data
print df.head()

# check data types
df.dtypes

#Check and take care of "NaN"
# Convert to numpy nan
df.replace(to_replace='NaN', value = numpy.nan, inplace=True)


# Count number of NaN's for columns
print df.isnull().sum()

# DataFrame dimeansion
print df.shape
# print df.head()


df_imp = df.replace(to_replace = numpy.nan, value=0)
# The fillna function can “fill in” NA values with non-null data
df_imp = df.fillna(0).copy(deep=True)
df_imp.columns = list(df.columns.values)


print df_imp.isnull().sum()
print df_imp.head()

df_imp.describe()


#Feature Selection:
##Try pairgrid to see what features popout more than others:
import seaborn as sns
import matplotlib.pyplot as plt

g = sns.PairGrid(df)
g.map(plt.scatter);


## Try heatmap to see what features popout more than others:
from string import letters
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt


sns.set(style="white")


# Compute the correlation matrix
corr = df.corr()

# Generate a mask for the upper triangle
mask = np.zeros_like(corr, dtype=np.bool)
mask[np.triu_indices_from(mask)] = True

# Set up the matplotlib figure
f, ax = plt.subplots(figsize=(20, 15))

# Generate a custom diverging colormap
cmap = sns.diverging_palette(220, 10, as_cmap=True)

# Draw the heatmap with the mask and correct aspect ratio
sns.heatmap(corr, mask=mask, cmap=cmap, vmax=.3,
            square=True, xticklabels=2, yticklabels=2,
            linewidths=.5, cbar_kws={"shrink": .5}, ax=ax)


##Try Correlation and Corrplot to see what features popout more than others:
df.corr(method='pearson')
pearson = df.corr(method='pearson')

# print pearson
# assume target attr is the last, then remove corr with itself
corr_with_target = pearson.ix[-7][:-1]
#print pearson.ix
print corr_with_target

# correlations by the absolute value:
corr_with_target[abs(corr_with_target).argsort()[::-1]]


# Set up the matplotlib figure
f, ax = plt.subplots(figsize=(20, 15))
sns.corrplot(df) # compute and plot the pair-wise correlations

# save to file, remove the big white borders
plt.savefig('attribute_correlations.png', tight_layout=True)


## Use scikit-learn's SelectKBest feature selection:
def get_k_best(enron_data, features_list, k):
    """ runs scikit-learn's SelectKBest feature selection
        returns dict where keys=features, values=scores
    """
    data = featureFormat(enron_data, features_list)
    labels, features = targetFeatureSplit(data)

    k_best = SelectKBest(k=k)
    k_best.fit(features, labels)
    scores = k_best.scores_
    unsorted_pairs = zip(features_list[1:], scores)
    sorted_pairs = list(reversed(sorted(unsorted_pairs, key=lambda x: x[1])))
    k_best_features = dict(sorted_pairs[:k])

    # print "{0} best features: {1}\n".format(k, k_best_features.keys())
    # print k_best_features
    return k_best_features


# get K-best features
target_label = 'poi'
from sklearn.feature_selection import SelectKBest

num_features = 10 # 10 best features
best_features = get_k_best(enron_data, features_list, num_features)
print best_features
my_feature_list = [target_label] + best_features.keys()
# print my_feature_list

print "{0} selected features: {1}\n".format(len(my_feature_list) - 1, my_feature_list[1:])



#Feature Engineering:
import warnings
warnings.filterwarnings('ignore')

#Engineerd Features are:
eng_feat1='poi_ratio'
eng_feat2='fraction_to_poi'
eng_feat3='fraction_from_poi'


# add'em
enron.add_poi_ratio(enron_data, my_feature_list)
enron.add_fraction_to_poi(enron_data, my_feature_list)
enron.add_fraction_from_poi(enron_data, my_feature_list)


eng_feature_list=my_feature_list #+ [eng_feat1] + [eng_feat2] + [eng_feat3]
print my_feature_list
print eng_feature_list


#Feature Scaling:
# extract the features specified in features_list
data = featureFormat(enron_data, eng_feature_list)
labels, features = targetFeatureSplit(data)

# scale features via min-max
from sklearn import preprocessing
scaler = preprocessing.MinMaxScaler()
features = scaler.fit_transform(features)


#splitting data into training and test:
features_train,features_test,labels_train,labels_test = sklearn.cross_validation.train_test_split(features,labels, test_size=0.3, random_state=42)


print labels
print features

#Looking at different models
###Let us iterarte through list to pick the best models.
 
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import ExtraTreesClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.naive_bayes import GaussianNB

names = ["Nearest Neighbors", "Linear SVM", "RBF SVM", "Decision Tree",
         "Random Forest", "AdaBoost", "Naive Bayes", "Extra Trees"]

classifiers = [
    KNeighborsClassifier(3),
    SVC(kernel="linear", C=0.025),
    SVC(gamma=2, C=1),
    DecisionTreeClassifier(max_depth=5),
    RandomForestClassifier(max_depth=5, n_estimators=10, max_features=1),
    AdaBoostClassifier(),
    GaussianNB(),
    ExtraTreesClassifier()]


# iterate over classifiers
for name, clf in zip(names, classifiers):
        clf.fit(features_train,labels_train)
        scores = clf.score(features_test,labels_test)
        print " "
        print "Classifier:"
        evaluate.evaluate_clf(clf, features, labels, num_iters=1000, test_size=0.3)
        print("Accuracy: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))
        print "====================================================================="


# Model tuning using grid_search.GridSearchCV
# define cv and scoring
from sklearn import grid_search
from sklearn.tree import DecisionTreeClassifier


cv = sklearn.cross_validation.StratifiedShuffleSplit(labels, n_iter=10)
def scoring(estimator, features_test, labels_test):
    labels_pred = estimator.predict(features_test)
    p = sklearn.metrics.precision_score(labels_test, labels_pred, average='micro')
    r = sklearn.metrics.recall_score(labels_test, labels_pred, average='micro')
    if p > 0.3 and r > 0.3:
        return sklearn.metrics.f1_score(labels_test, labels_pred, average='macro')
    return 0


# DecisionTreeClassifier tunning
t0 = time()
parameters = {'max_depth': [1,2,3,4,5,6,8,9,10],'min_samples_split':[1,2,3,4,5],'min_samples_leaf':[1,2,3,4,5,6,7,8], 'criterion':('gini', 'entropy')}

dtc_clf = sklearn.tree.DecisionTreeClassifier() 
dtcclf = grid_search.GridSearchCV(dtc_clf, parameters, scoring = scoring, cv = cv)

dtcclf.fit(features, labels)
print dtcclf.best_estimator_
print dtcclf.best_score_
print 'Processing time:',round(time() - t0, 3) ,'s'


#Classifier validation
##DecisionTreeClassifier Validation 1 (StratifiedShuffleSplit, folds = 1000)
t0 = time()
dtc_best_clf = dtcclf.best_estimator_   
test_classifier(dtc_best_clf, enron_data, eng_feature_list)

print 'Processing time:',round(time()-t0,3) ,'s'


##DecisionTreeClassifier Validation 2 (Randomized, partitioned trials, n=1,000)
t0 = time()
dtc_best_clf = dtcclf.best_estimator_
   
evaluate.evaluate_clf(dtc_best_clf, features, labels, num_iters=1000, test_size=0.3)
print("Accuracy: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))
print 'Processing time:',round(time()-t0,3) ,'s'

#Dump my classifier
dump_classifier_and_data(dtc_best_clf, enron_data, eng_feature_list)

