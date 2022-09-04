# Creating the required data element to store the data
fileData = None
# Menu Driven While Loop
while True:
    # Required Menu Options
    menuOption = int(input("Please enter the menu Option\n1.Write\n2.Read\n3.Search\n4.Exit\n"))

    # Menu Option 1 For Write
    if menuOption == 1:
        num_books = int(input("Please enter the number of books to be inserted\n"))
        # boundary condition
        if num_books <= 0:
            print("Please enter a valid number\n")
            continue
        for i in range(num_books):
            ISSN = input("Please enter the ISSN\n")
            title = input("Please enter the title\n")
            price = input("Please enter the price\n")
            edition = input("please enter the edition\n")
            author_name = input("Please enter the author name\n")
            reqDetails = [ISSN, title, price, edition, author_name]
            # Opening The File in Append Mode
            with open('books.txt', 'a') as reqFile:
                # Writing into the file by joining the data seperated by a comma
                reqFile.write(",".join(reqDetails)+"\n")

    # Menu Option 2 to read from the file
    elif menuOption == 2:
        # try except block to handle file not found error
        try:
            # opening the file in read mode
            with open("books.txt", 'r') as reqFile:
                # reading the lines of the files as a list
                fileData = reqFile.readlines()
                print("File Read Complete")
        except FileNotFoundError:
            print("No Data Entered into the file")
            continue
        # splitting each line of the list with the delimiter as a comma and storing it back
        for i in range(len(fileData)):
            fileData[i] = fileData[i].split(",")

    # menu option to search for a particular title
    elif menuOption == 3:
        title = input("Please enter the title to be searched for\n")
        boolean = False
        # handling if the file has not been read yet
        if fileData is None:
            print("The file has not been read")
            continue
        # searching and printing the required book
        else:
            for i in fileData:
                if i[1] == title:
                    print("The required book details are")
                    print("ISSN Title price edition authorName")
                    print("  ".join(i))
        if not boolean:
            print("The required title does not exist")

    # menu option to exit
    elif menuOption == 4:
        print("GoodBye!")
        break

    # wrong option entered menu option
    else:
        print("Please enter the proper menu option")
