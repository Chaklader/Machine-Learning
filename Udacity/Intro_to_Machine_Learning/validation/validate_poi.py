#!/usr/bin/python

"""
    Starter code for the validation mini-project.
    The first step toward building your POI identifier!

    Start by loading/formatting the data
    After that, it's not our code anymore--it's yours!
"""

import pickle
import sys
sys.path.append("../tools/")

from feature_format import featureFormat, targetFeatureSplit
from sklearn.tree import DecisionTreeClassifier
from sklearn import cross_validation

data_dict = pickle.load(open("../final_project/final_project_dataset.pkl", "r") )


### first element is our labels, any added elements are predictor
### features. Keep this the same for the mini-project, but you'll
### have a different feature list when you do the final project.
features_list = ["poi", "salary"]

data = featureFormat(data_dict, features_list)
labels, features = targetFeatureSplit(data)


### it's all yours from here forward!  


### it's all yours from here forward!  
clf = DecisionTreeClassifier()
clf.fit(features, labels)
clf.score(features,labels)
# 0.98958333333333337


# Now, youll add in training and testing, so that you get a trustworthy accuracy number. 
# Use the training_test_split validation available in sklearn.cross_validation
features_train, features_test, labels_train, labels_test = cross_validation.train_test_split(features,
                labels,test_size=0.3,random_state=42)
                
clf = DecisionTreeClassifier()
clf.fit(features_train, labels_train)
print clf.score(features_test,labels_test)
# 0.72413793103448276

