# creating the required empty dictionary
required_dictionary = {}
# menu-driven while condition
while True:
    continuity = int(input("Please enter 1 to enter an item, 2 to search for an item, 3 to delete, 4 to print the dictionary and 5 to exit\n"))
    if continuity == 1:
        roll_number = input("Please enter the roll number of the candidate\n")
        if roll_number in required_dictionary:
            print('the required roll number already exist, do you want to over write, y or n')
            o_write = input()
            if o_write == 'y':
                pass
            elif o_write == 'n':
                continue
        name = input("Please enter the name of the candidate\n")
        CGPA = input("Please enter the CGPA of the candidate\n")
        phone_number = input("Please enter the Phone number of the candidate\n")
        required_dictionary[roll_number] = [name, CGPA, phone_number]
    elif continuity == 2:
        roll_number = input("Please enter the roll number of the candidate\n")
        if roll_number in required_dictionary:
            print("The roll number is "+roll_number)
            print("the details are")
            print(required_dictionary[roll_number])
        else:
            print('Sorry The required roll number cannot be found')
    elif continuity == 3:
        roll_number = input("Please enter the roll number of the candidate\n")
        if roll_number in required_dictionary:
            required_dictionary.pop(roll_number)
        else:
            print('Sorry The required roll number cannot be found')
    elif continuity == 4:
        print(required_dictionary)
    elif continuity == 5:
        break
