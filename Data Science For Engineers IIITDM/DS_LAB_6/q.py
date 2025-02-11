# Programmed By Sravanth Chowdary Potluri CS20B1006

# importing the required libraries
import pandas as pd

# initial dataframe
init_df = pd.DataFrame({'Name': ['Ram', 'Sam', 'Prabhu'],
                        'Account Number': ['98938993891', '9893893898', '9893893871'],
                        'Account Type': ['SB', 'CA', 'SB'],
                        'Aadhaar Number': ['959389389173', '959389389179', '959389389159'],
                        'Balance': [8989839, 7690990, 989330]})

# storing the dataframe in the csv file
init_df.to_csv("SBIAccountHolder.csv")

print("CSV File Created")


#required menu driven program

while True:
    menu_option = int(input("""Please enter the menu option 
    1.append
    2.delete
    3.credit
    4.debit
    5.print
    6.exit\n"""))
    if menu_option == 1:
        req_details = {'Name': [],
                       'Account Number': [],
                       'Account Type': [],
                       'Aadhaar Number': [],
                       'Balance': []}
        req_details['Name'].append((input("Please enter the Name\n")))
        req_details['Account Number'].append(input("Please enter the account number\n"))
        req_details['Account Type'].append(input("Please enter the account type\n"))
        req_details['Aadhaar Number'].append(input("Please enter the aadhar number\n"))
        req_details['Balance'].append(int(input("Please enter the account balance\n")))
        new_df = pd.DataFrame(req_details)
        init_df = pd.concat([init_df, new_df], ignore_index=True).reset_index(drop=True)
        print("Account Added")
    elif menu_option == 2:
        ac_num = input('Please enter the account number\n')
        init_df = init_df.loc[init_df['Account Number'] != ac_num]
        init_df=init_df.reset_index(drop=True)
        print("Account Successfully Deleted/Account Not Present\n")
    elif menu_option == 3:
        ac_num = input("Please enter the account number\n")
        index = 0
        while index <= len(init_df.index):
            if init_df.at[index, 'Account Number'] == ac_num:
                credit_amount = int(input("Please enter the credit amount\n"))
                init_df.at[index, "Balance"] += credit_amount
                print("Amount Credited")
                break
            else:
                index += 1
        print("The Account Does not exist")
    elif menu_option == 4:
        ac_num = input("Please enter the account number\n")
        index = 0
        while index <= len(init_df.index):
            if init_df.at[index, 'Account Number'] == ac_num:
                debit_amount = int(input("Please enter the debit amount"))
                if init_df.at[index, 'Account Type'] == 'SB':
                    if init_df.at[index, "Balance"] - debit_amount <0:
                        print("Account balance cannot be less than zero,amount not debited")
                    else:
                        init_df.at[index, "Balance"] -= debit_amount
                        print("Amount Debited")
                else:
                    init_df.at[index, "Balance"] -= debit_amount
                    print("Amount Debited")
                break
            else:
                index += 1
        print("The Account Does not exist")
    elif menu_option == 5:
        ac_num = input("Please enter the account number")
        index = 0
        while index <= len(init_df.index):
            if init_df.at[index, 'Account Number'] == ac_num:
                print("The account details are")
                print(init_df.iloc[index])
                break
            else:
                index += 1
        print("The Account Does not exist")
    elif menu_option == 6:
        break
    else:
        print("Please enter a valid menu option")
    print("The current dataframe is")
    print(init_df)


# merging the dataframes
init_df = pd.DataFrame({'Name': ['Ram', 'Sam', 'Prabhu'],
                        'Account Number': ['98938993891', '9893893898', '9893893871'],
                        'Account Type': ['SB', 'CA', 'SB'],
                        'Aadhaar Number': ['959389389173', '959389389179', '959389389159'],
                        'Balance': [8989839, 7690990, 989330]})

final_df = pd.DataFrame({'Name': ['Ram', 'Sam', 'Prabhu'],
                         'Aadhaar Number': ['959389389173', '959389389179', '959389389159'],
                         'Contact No': ['9840787333', '9840787343', '9840787353'],
                         'DOB': ['12-2-1990', '12-2-2000', '12-2-2010'],
                         'Address': ['No. 23, Kandigai, Chennai 127', 'No.73, Melakottaiyu, Chennai 127',
                                     'No. 43, Anna Nagar, Chennai 102']
                         })

final_df.to_csv("Aadhar_DB.csv")

merged_df = pd.merge(init_df, final_df)
print(merged_df)
merged_df.to_csv("Merged_DB.csv")
