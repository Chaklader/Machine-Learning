import matplotlib.pyplot as plt
import sys
import pickle
import numpy as np
from ggplot import *

sys.path.append("../tools/") # moved this directory to local to make 
								# it easy to put all in one git repo
sys.path.append("./tools/")


    
def computeFraction( poi_messages, all_messages ):
    """ given a number messages to/from POI (numerator) 
        and number of all messages to/from a person (denominator),
        return the fraction of messages to/from that person
        that are from/to a POI
   """
    
    if all_messages == 'NaNNaN': # occurred when created additive features (all emails)
        all_messages = 'NaN'
    if poi_messages == 'NaNNaN':
        poi_messages = 'NaN'
    if all_messages == 'NaN':
        return 0
    if poi_messages == 'NaN':
        return 0
    if all_messages == 0:
        return 0
    return 1.*poi_messages/all_messages
    return fraction


def scaleFeatures(arr):  # scaled features. Not used in final, but when testing out kmeans algorithm

    for i in range(1,arr.shape[1]):
        arrmin = min(arr[:,i])
        arrmax = max(arr[:,i])

        if arrmin == arrmax:
            arr[:,i] = arr[:,i]/arrmin
        else:
            arr[:,i] = (arr[:,i]-arrmin)/(arrmin-arrmax)
    return arr  



def algorithm(data_dict, features_list):

    from feature_format import featureFormat
    from feature_format import targetFeatureSplit
   
    ### store to my_dataset for easy export below
    my_dataset = data_dict
    data = featureFormat(my_dataset, features_list)

    # scale features
    #data = scaleFeatures(data)
    
    ### split into labels and features (this line assumes that the first
    ### feature in the array is the label, which is why "poi" must always
    ### be first in features_list
    labels, features = targetFeatureSplit(data)
    
    from sklearn.ensemble import AdaBoostClassifier
    clf = AdaBoostClassifier(n_estimators = 1000, random_state = 202, \
    		learning_rate = 1.0, algorithm = "SAMME.R")
    
    ### dump your classifier, dataset and features_list so 
    ### anyone can run/check your results
    pickle.dump(clf, open("my_classifier.pkl", "w") )
    pickle.dump(data_dict, open("my_dataset.pkl", "w") )
    pickle.dump(features_list, open("my_feature_list.pkl", "w") )

    
def create_features(data_dict):
    
    ### if you are creating any new features, you might want to do that here
    # have some ideas for new features
    for name in data_dict:

        poi_msg_to = data_dict[name]['from_poi_to_this_person']
        all_msg_to = data_dict[name]['to_messages']
        data_dict[name]['fraction_from_poi'] = computeFraction(poi_msg_to, all_msg_to)
        poi_msg_from = data_dict[name]['from_this_person_to_poi']
        all_msg_from = data_dict[name]['from_messages']
        data_dict[name]['fraction_to_poi'] = computeFraction(poi_msg_from, all_msg_from)
        expenses = data_dict[name]['expenses']
        salary = data_dict[name]['salary']
        data_dict[name]['expenses_per_salary'] = computeFraction(expenses, salary)
        poi_msg_all = poi_msg_to + poi_msg_from
        all_msg_all = all_msg_to + all_msg_from
        data_dict[name]['fraction_emails_with_poi'] = computeFraction(poi_msg_all, all_msg_all)
     
    return data_dict


def load_data():
    ### load the dictionary containing the dataset
    data_dict = pickle.load(open("final_project_dataset.pkl", "r") )
    
    data_dict.pop('TOTAL',0)  # spreadsheet phenomenon
    data_dict.pop('LOCKHART EUGENE E',0)  # all data 0 or N/A -- not helpful
    
    return data_dict


def main():
    data_dict = load_data()
    data_dict = create_features(data_dict)
    
    selected_featurenames = ["poi", "salary", "bonus", "expenses", "deferral_payments"]
    algorithm(data_dict, selected_featurenames)


if __name__ == "__main__": 
	main()