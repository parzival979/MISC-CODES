# programmed by Sravanth Chowdary Potluri cs20b1006

# importing the required libraries
import numpy as np
import pandas as pd

# importing the csv file
diabetes_df = pd.read_csv("diabetes.csv")

# required menu driven while loop
while True:

    # required menu options
    menu_option = int(input("""Please enter the menu option
    1.probability of diabetes age above 50
    2.probability of diabetes age between 40 and 50
    3.probability of diabetes age between 30 and 40
    4.probability of diabetes age less than 30
    5.probability of diabetes with a glucose of 120+,bp of 90+,skin thickness of 30+,insulin 150+,bmi 25+
    6.exit"""))

    if menu_option == 1:
        n_sample_space = len(diabetes_df.loc[diabetes_df["Age"] > 50])
        favourable_event = len(diabetes_df.loc[np.logical_and(diabetes_df["Age"] > 50, diabetes_df["Outcome"] == 1)])
        print("The Numerator and denominator are")
        print(favourable_event, n_sample_space)
        print("The Required Probability is")
        print(favourable_event / n_sample_space)
    elif menu_option == 2:
        n_sample_space = len(diabetes_df.loc[np.logical_and(diabetes_df["Age"] > 40, diabetes_df["Age"] < 50)])
        favourable_event = len(diabetes_df.loc[
                                   np.logical_and(np.logical_and(diabetes_df["Age"] > 40, diabetes_df["Age"] < 50),
                                                  diabetes_df["Outcome"] == 1)])
        print("The Numerator and denominator are")
        print(favourable_event, n_sample_space)
        print("The Required Probability is")
        print(favourable_event / n_sample_space)
    elif menu_option == 3:
        n_sample_space = len(diabetes_df.loc[np.logical_and(diabetes_df["Age"] > 30, diabetes_df["Age"] < 40)])
        favourable_event = len(diabetes_df.loc[
                                   np.logical_and(np.logical_and(diabetes_df["Age"] > 30, diabetes_df["Age"] < 40),
                                                  diabetes_df["Outcome"] == 1)])
        print("The Numerator and denominator are")
        print(favourable_event, n_sample_space)
        print("The Required Probability is")
        print(favourable_event / n_sample_space)
    elif menu_option == 4:
        n_sample_space = len(diabetes_df.loc[diabetes_df["Age"] < 30])
        favourable_event = len(diabetes_df.loc[np.logical_and(diabetes_df["Age"] < 30, diabetes_df["Outcome"] == 1)])
        print("The Numerator and denominator are")
        print(favourable_event, n_sample_space)
        print("The Required Probability is")
        print(favourable_event / n_sample_space)
    elif menu_option == 5:
        n_sample_space = len(diabetes_df.loc[np.logical_and(diabetes_df["Glucose"] > 120,
                                                            np.logical_and(diabetes_df["BloodPressure"] > 90,
                                                                           np.logical_and(
                                                                               diabetes_df["SkinThickness"] > 30,
                                                                               np.logical_and(
                                                                                   diabetes_df["Insulin"] > 150,
                                                                                   diabetes_df["BMI"] > 25))))])
        favourable_event = len(diabetes_df.loc[np.logical_and(
            np.logical_and(diabetes_df["Glucose"] > 120, np.logical_and(diabetes_df["BloodPressure"] > 90,
                                                                        np.logical_and(
                                                                            diabetes_df["SkinThickness"] > 30,
                                                                            np.logical_and(diabetes_df["Insulin"] > 150,
                                                                                           diabetes_df["BMI"] > 25)))),
            diabetes_df["Outcome"] == 1)])
        print("The Numerator and denominator are")
        print(favourable_event, n_sample_space)
        print("The Required Probability is")
        print(favourable_event / n_sample_space)
    elif menu_option == 6:
        break
    else:
        print("Please enter a valid menu option")
