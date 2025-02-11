#!/usr/bin/env python
# coding: utf-8

# In[161]:


# importing the required libraries
import numpy as np
import pandas as pd


# In[162]:


# taking the required dataframes from the csv
train_df = pd.read_csv("diabetes.csv")[:615]


# In[163]:


# separating on the basis of outcome and removing the outcome column
outcome_1_df = train_df.loc[train_df['Outcome']==1]
outcome_2_df = train_df.loc[train_df['Outcome']==0]
outcome_1_df=outcome_1_df.drop(columns=['Outcome'])
outcome_2_df=outcome_2_df.drop(columns=['Outcome'])


# In[164]:


# lists containing the means
outcome_1_mean = []
outcome_2_mean = []

# calculating the mean for each feature of each outcome
outcome_1_mean.append(np.mean(outcome_1_df['Pregnancies']))
outcome_1_mean.append(np.mean(outcome_1_df['Glucose']))
outcome_1_mean.append(np.mean(outcome_1_df['BloodPressure']))
outcome_1_mean.append(np.mean(outcome_1_df['SkinThickness']))
outcome_1_mean.append(np.mean(outcome_1_df['Insulin']))
outcome_1_mean.append(np.mean(outcome_1_df['BMI']))
outcome_1_mean.append(np.mean(outcome_1_df['Age']))

outcome_2_mean.append(np.mean(outcome_2_df['Pregnancies']))
outcome_2_mean.append(np.mean(outcome_2_df['Glucose']))
outcome_2_mean.append(np.mean(outcome_2_df['BloodPressure']))
outcome_2_mean.append(np.mean(outcome_2_df['SkinThickness']))
outcome_2_mean.append(np.mean(outcome_2_df['Insulin']))
outcome_2_mean.append(np.mean(outcome_2_df['BMI']))
outcome_2_mean.append(np.mean(outcome_2_df['Age']))


# In[165]:


# preparing the test data
test_df = pd.read_csv("diabetes.csv")[615:]
test_df = test_df.reset_index(drop=True)
test_df = test_df.drop(columns=["Outcome"])
print(test_df)


# In[166]:


# list of final list of outcomes using minimum distance classifier
final_list_of_outcomes = []

# looping to find the distance and to decide the outcome
for i in range(len(test_df)):
    outcome = None
    req_arr = np.array(test_df.loc[i])
    dist_1 = np.sum((req_arr-outcome_1_mean)**2)
    dist_2 = np.sum((req_arr-outcome_2_mean)**2)
    if dist_1<=dist_2:
        final_list_of_outcomes.append(1)
    else:
        final_list_of_outcomes.append(0)


print("The Final list of outcomes from using user written minimum distance classifier is")
print(np.array(final_list_of_outcomes))


# In[167]:


# let us use outcome 1 and outcome 2 means as centroids for out clusters

train_df=train_df.drop(columns=["Outcome"])

cluster_1_mean = outcome_1_mean
cluster_2_mean = outcome_2_mean

cluster_1_nos =1
cluster_2_nos =1

#training our model
for i in range(len(train_df)):
    req_arr = np.array(train_df.loc[i])
    dist_1 = np.sum((req_arr-cluster_1_mean)**2)
    dist_2 = np.sum((req_arr-cluster_2_mean)**2)
    if dist_1<=dist_2:
        cluster_1_mean = ((cluster_1_mean*cluster_1_nos)+req_arr)/(cluster_1_nos+1)
        cluster_1_nos+=1
    else:
        cluster_2_mean = ((cluster_2_mean*cluster_2_nos)+req_arr)/(cluster_2_nos+1)
        cluster_2_nos+=1


# In[168]:


# looping to find the distance and to predict the cluster
final_list_of_clusters = []
for i in range(len(test_df)):
    outcome = None
    req_arr = np.array(test_df.loc[i])
    dist_1 = np.sum((req_arr-cluster_1_mean)**2)
    dist_2 = np.sum((req_arr-cluster_2_mean)**2)
    if dist_1<=dist_2:
        final_list_of_clusters.append(1)
    else:
        final_list_of_clusters.append(0)


print("The Final list of clusters from using k-means clustering is")
print(np.array(final_list_of_clusters))
