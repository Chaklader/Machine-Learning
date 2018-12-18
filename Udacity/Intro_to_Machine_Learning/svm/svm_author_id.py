#!/usr/bin/python

""" 
    This is the code to accompany the Lesson 2 (SVM) mini-project.

    Use a SVM to identify emails from the Enron corpus by their authors:    
    Sara has label 0
    Chris has label 1
"""
    
import sys
from time import time

sys.path.append("../tools/")
from email_preprocess import preprocess
from sklearn.svm import SVC

from sklearn.metrics import accuracy_score
import numpy as np

### features_train and features_test are the features for the training
### and testing datasets, respectively
### labels_train and labels_test are the corresponding item labels
features_train, features_test, labels_train, labels_test = preprocess()




#########################################################
### your code goes here ###

#########################################################


#########################################################
# features_train = features_train[:len(features_train)/100] 
# labels_train = labels_train[:len(labels_train)/100] 

# clf = SVC(kernel ='rbf')

# if we increase the value for the C, 
# the accuracy will also be increased. 

clf = SVC(C=10000.0, kernel ='rbf')
# clf = SVC(kernel = "linear")


t0 = time()
clf.fit(features_train, labels_train)
print "training time:", round(time()-t0, 3), "s"


t0 = time()
pred = clf.predict(features_test)
print "predicting time:", round(time()-t0, 3), "s"

acc = accuracy_score(pred, labels_test)
print "accuracy = ", acc


# # Check the prediction of element 10
# print "pred[10]", pred[10]


# # Check the prediction of element 26
# print "pred[26]", pred[26]

# # Check the prediction of element 50
# print "pred[50]", pred[50]


# Count the occurences in a list
# will make the list of {0, 1} fequencies 
print np.bincount(pred)
#  [881 877]  {0, 1} fequencies 
#  Sara 0 
#  Chris 1
