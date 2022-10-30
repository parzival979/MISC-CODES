# Programmed By Sravanth Chowdary Potluri CS20B1006

import numpy as np
import pandas as pd
from pandas_profiling import ProfileReport
import matplotlib.pyplot as plt

df = pd.read_csv('diabetes1.csv')

profile=ProfileReport(df,title='Diabetes Report')

profile.to_file("main_report.html")

for i in df.columns:
    if(i!='Outcome'):
        print("The Required Mean of " + str(i) + " is " + str(np.mean(np.array(df[i]))))
        print("The Required Median of " + str(i) + " is " + str(np.median(np.array(df[i]))))
        values, counts = np.unique(np.array(df[i]), return_counts=True)
        indexOf = np.argmax(counts)
        print("The Required Mode of " + str(i) + " is " + str(values[indexOf]))
        print("The Required Minimum of " + str(i) + " is " + str(np.min(np.array(df[i]))))
        print("The Required Maximum of " + str(i) + " is " + str(np.max(np.array(df[i]))))
        print("The Required Standard Deviation of " + str(i) + " is " + str(np.std(np.array(df[i]))))

for i in df.columns:
    if(i != 'Outcome'):
        print("The Required correlation coefficient between Age and " +str(i) + " is " + str(df['Age'].corr(df[i])))
        print("The Required correlation coefficient between BMI and " +str(i) + " is " + str(df['BMI'].corr(df[i])))

for i in df.columns:
    if(i != 'Outcome'):
        plt.scatter(df['Age'], df[i])
        plt.xlabel('Age')
        plt.ylabel(i)
        plt.title("Age vs "+str(i))
        plt.show()
        plt.scatter(df['BMI'], df[i])
        plt.xlabel('BMI')
        plt.ylabel(i)
        plt.title("BMI vs " + str(i))
        plt.show()



df.hist(column='Pregnancies')
plt.show()
df.hist(column='SkinThickness')
plt.show()


df.hist(column='Pregnancies', by='Outcome')
plt.show()

for i in df.columns:
    if(i != 'Outcome'):
        plt.boxplot(np.array(df[i]))
        plt.title(i)
        plt.show()