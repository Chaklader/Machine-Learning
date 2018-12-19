import sys

import numpy as np
import pylab as pl

from class_vis import prettyPicture
from prep_terrain_data import makeTerrainData

features_train, labels_train, features_test, labels_test = makeTerrainData()

from sklearn import tree
from sklearn.metrics import accuracy_score

#### your code goes here
clf = tree.DecisionTreeClassifier()
clf.fit(features_train, labels_train)   
pred = clf.predict(features_test)

acc = accuracy_score(pred, labels_test)

### be sure to compute the accuracy on the test set
def submitAccuracies():
  return {"acc":round(acc,3)}
    
print submitAccuracies()



    


