# Programmed By Sravanth Chowdary Potluri CS20B1006

# Importing the required libraries
import numpy as np
import pandas as pd


# Part A
# reading the csv file into a dataframe
required_dataframe = pd.read_csv("file4.csv")

# printing the initial dataframe
print("Printing the inital dataframe")
print(required_dataframe)

# putting the rows that don't have calories as 300 in the dataframe
required_dataframe = required_dataframe.loc[required_dataframe["Calories"] != 300]
# printing the dataframe
print("Printing the dataframe after removing people with 300 calories")
print(required_dataframe)

# resetting the indices and printing the dataframe again
required_dataframe = required_dataframe.reset_index()
print("printing the dataframe after resetting the indices")
print(required_dataframe)

# Setting the required fit value according to given criteria
required_dataframe["Status"][
    np.logical_and(required_dataframe["Duration"] == 60, required_dataframe["Pulse"] > 100)] = "FIT"
# printing the required data frame
print("printing the dataframe after using the required fit criteria")
print(required_dataframe)




# PartB
# taking input from the user of number of elements in the list
print("Please enter the number of elements in the list")
num_elements = int(input())

# creating the required empty input list
req_list = []

# for loop to take the list elements
for i in range(num_elements):
    req_list.append(int(input("Please enter the List Element\n")))

print("The entered list is")
print(req_list)
# Value of K to prepare the required list of sets
k_val = int(input("Please enter the value of K\n"))

# removing the duplicates
req_list = list(set(req_list))
print("The list after removing the duplicates is")
print(req_list)

# sorting the elements
req_list.sort()
print("The final pre-processed(sorted) list is")
print(req_list)

# final required list
final_list = []

# loop counter variables
i = 0
j = 0

# algorithm to get the final output
while i < len(req_list):
    current_set = set()
    while j < k_val:
        current_set.add(req_list[i])
        i += 1
        if i == len(req_list):
            break
        j += 1
    final_list.append(current_set)
    j = 0

# printing the final list
print("The Final Required List is")
print(final_list)
