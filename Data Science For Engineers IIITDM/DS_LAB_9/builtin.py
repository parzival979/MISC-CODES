# importing the required libraries
import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
from sklearn.neighbors import KNeighborsClassifier


# taking the required dataframes from the csv
train_df = pd.read_csv("diabetes.csv")[:615]


# converting the dataframe into a numpy array
train_arr = np.array(train_df)


# training the model
kMeans = KMeans(n_clusters=2,random_state=2).fit(train_arr)


# taking the required dataframes from the csv
test_df = pd.read_csv("diabetes.csv")[615:]


test_arr = np.array(test_df)


print("The required output of clusters for the test data is")
print(kMeans.predict(test_arr))


# removing the outcome column and putting it in another array
outcome_arr = np.array(train_df['Outcome'])
train_df = train_df.drop(columns=['Outcome'])
train_arr = np.array(train_df)


# k neighbors classifier with number of neighbors = 1
classifier = KNeighborsClassifier(n_neighbors=1).fit(train_arr,outcome_arr)


# removing the outcome from the test data
test_df = test_df.drop(columns=['Outcome'])
test_arr=np.array(test_df)

# predicting the outcomes for the test data and printing
print("The Required Outcomes/Labels For the test data is")
print(classifier.predict(test_arr))
