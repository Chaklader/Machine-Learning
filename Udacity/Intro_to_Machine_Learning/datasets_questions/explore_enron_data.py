#!/usr/bin/python

""" 
    Starter code for exploring the Enron dataset (emails + finances);
    loads up the dataset (pickled dict of dicts).

    The dataset has the form:
    enron_data["LASTNAME FIRSTNAME MIDDLEINITIAL"] = { features_dict }

    {features_dict} is a dictionary of features associated with that person.
    You should explore features_dict as part of the mini-project,
    but here's an example to get you started:

    enron_data["SKILLING JEFFREY K"]["bonus"] = 5600000    
"""

import pickle

enron_data = pickle.load(open("../final_project/final_project_dataset.pkl", "r"))



#  features list 
#  -------------
# {
#     'salary': 365788, 
#     'to_messages': 807, 
#     'deferral_payments': 'NaN', 
#     'total_payments': 1061827, 
#     'exercised_stock_options': 'NaN', 
#     'bonus': 600000, 
#     'restricted_stock': 585062, 
#     'shared_receipt_with_poi': 702, 
#     'restricted_stock_deferred': 'NaN', 
#     'total_stock_value': 585062, 
#     'expenses': 94299, 
#     'loan_advances': 'NaN', 
#     'from_messages': 29, 
#     'other': 1740, 
#     'from_this_person_to_poi': 1, 
#     'poi': False, 
#     'director_fees': 'NaN', 
#     'deferred_income': 'NaN', 
#     'long_term_incentive': 'NaN', 
#     'email_address': 'mark.metts@enron.com', 
#     'from_poi_to_this_person': 38
# }


# How many data points (people) are in the dataset?
print "number of data points = ", len(enron_data)
# print "number of data keys = ", len(enron_data.keys())


# For each person, how many features are available?
print len(enron_data.values()[0])
enron_data[enron_data.keys()[0]]
len(enron_data['SKILLING JEFFREY K'])


# How many POIs are there in the E+F dataset
# Example 1:
# ----------

# count = 0

# for i in range(len(enron_data)):
#     a = enron_data.values()
#     if a[i]['poi']:
#         count = count + 1  


count = 0

pois = [x for x, y in enron_data.items() if y['poi']]
print len(pois)

# for user in enron_data:
#     if enron_data[user]['poi']:
#         count+=1

# print "number of POIs = ", count


# How Many POIs Exist?
# 1
poi_names = open("../final_project/poi_names.txt", 'r')
fr = poi_names.readlines()

print "number of POIs using the email address = ", len(fr[2:])
# print poi_names.read()
poi_names.close()


# poi_text = "final_project/poi_names.txt"

# 2
# poi_text = "../final_project/poi_names.txt"
# num_lines = sum(1 for line in open(poi_text))
# print num_lines -2 



# # 3
# def file_len(fname):

#     with open(fname) as f:
#         for i, l in enumerate(f):
#             pass
#     return i + 1

# print file_len("../final_project/poi_names.txt") - 2


# Check if values exist in any string in the list
matching = [s for s in enron_data.keys() if "PRENTICE" in s]
print matching


# What is the total value of the stock belonging to James Prentice?
print enron_data['PRENTICE JAMES']['total_stock_value']


# How many email messages do we have from Wesley Colwell to persons of interest?
print [s for s in enron_data.keys() if "COLWELL" in s]
enron_data['COLWELL WESLEY']
print "from Colwell to the POIs = ", enron_data['COLWELL WESLEY']['from_this_person_to_poi']


# Whats the value of stock options exercised by Jeffrey Skilling?
print [s for s in enron_data.keys() if "SKILLING" in s]
print "SKILLING JEFFREY K exercised_stock_options ", enron_data['SKILLING JEFFREY K']['exercised_stock_options']




enron_data[enron_data.keys()[1]]

# Sort values
sorted(enron_data.keys())



# How much money did that person get?
print enron_data['SKILLING JEFFREY K']['total_payments']
print enron_data['FASTOW ANDREW S']['total_payments']
print enron_data['LAY KENNETH L']['total_payments']


# How many folks in this dataset have a quantified salary?
# What about a known email address?
count_salary = 0
count_email = 0


for key in enron_data.keys():
    if enron_data[key]['salary'] != 'NaN':
        count_salary+=1
    if enron_data[key]['email_address'] != 'NaN':
        count_email+=1

print count_salary
print count_email



# How many people in the E+F dataset (as it currently exists) have NaN for their total payments?
# What percentage of people in the dataset as a whole is this?
count_NaN_tp = 0

for key in enron_data.keys():
    if enron_data[key]['total_payments'] == 'NaN':
        count_NaN_tp += 1

print count_NaN_tp

per =  float(count_NaN_tp)/len(enron_data.keys())
per1 = round(per,4) *100
print per1

        
# How many POIs in the E+F dataset have NaN for their total payments? 
# What percentage of POIs as a whole is this?   
count_NaN_tp = 0

for key in enron_data.keys():
    if enron_data[key]['poi'] and enron_data[key]['total_payments'] == 'NaN':
        count_NaN_tp+=1

print count_NaN_tp
print float(count_NaN_tp)/len(enron_data.keys())





