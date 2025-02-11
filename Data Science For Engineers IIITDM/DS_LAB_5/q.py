# This Program is done by Sravanth Chowdary Potluri CS20B1006

# importing the required numpy library
import numpy as np

while True:
    # required menu options
    menu_option = int(input("""Please select the menu option
                                1.Matrix Addition
                                2.Matrix Subtraction
                                3.Scalar Matrix Multiplication
                                4.Elementwise Matrix Multiplication
                                5.Matrix Multiplication
                                6.Matrix Transpose
                                7.Trace of a Matrix
                                8.Solve System of Linear Equations
                                9.Determinant
                                10.Inverse
                                11.Singular Value Decomposition
                                12.Eigen Value
                                13.Search an Element
                                14.Difference of sum of Upper and Lower Triangular Matrix
                                15.Exit\n"""))
    '''the below menu options do the required tasks as given in the menu,however
    please note that some of the menu options require the input to be in a certain way such as only square matrices
    can have a determinant'''

    if menu_option == 1:
        m = int(input("Please enter the m of the matrix"))
        n = int(input("Please enter the n of the matrix"))
        l1 = []
        l2 = []
        m1 = None
        m2 = None
        print("Please enter the data for matrix 1")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        print("Please enter the data for matrix 2")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l2.append(row)
        m1 = np.array(l1)
        m2 = np.array(l2)
        try:
            print("The required sum of the matrices is")
            print(m1 + m2)
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 2:
        m = int(input("Please enter the m of the matrix"))
        n = int(input("Please enter the n of the matrix"))
        l1 = []
        l2 = []
        m1 = None
        m2 = None
        print("Please enter the data for matrix 1")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        print("Please enter the data for matrix 2")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l2.append(row)
        m1 = np.array(l1)
        m2 = np.array(l2)
        try:
            print("The required difference of the matrices is")
            print(m1 - m2)
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 3:
        m = int(input("Please enter the m of the matrix"))
        n = int(input("Please enter the n of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        scalar = int(input("please enter the required scalar for the matrix"))
        try:
            print("The scalar multiplication of the matrix is")
            print(scalar * m1)
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 4:
        m = int(input("Please enter the m of the matrix"))
        n = int(input("Please enter the n of the matrix"))
        l1 = []
        l2 = []
        m1 = None
        m2 = None
        print("Please enter the data for matrix 1")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        print("Please enter the data for matrix 2")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l2.append(row)
        m1 = np.array(l1)
        m2 = np.array(l2)
        try:
            print("The required element wise multiplication of the matrices is")
            print(m1 * m2)
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 5:
        m1 = int(input("Please enter the m of the matrix 1"))
        n1 = int(input("Please enter the n of the matrix 1"))
        m2 = int(input("Please enter the m of the matrix 2"))
        n2 = int(input("Please enter the n of the matrix 2"))
        if n1 != m2:
            print("The required dimensions of the matrices do not allow matrix multiplication")
            continue
        l1 = []
        l2 = []
        mat1 = None
        mat2 = None
        print("Please enter the data for matrix 1")
        for i in range(m1):
            row = []
            for j in range(n1):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        print("Please enter the data for matrix 2")
        for i in range(m2):
            row = []
            for j in range(n2):
                element = int(input("Please enter the element"))
                row.append(element)
            l2.append(row)
        mat1 = np.array(l1)
        mat2 = np.array(l2)
        try:
            print("The required matrix multiplication of the matrices is")
            print(mat1 @ mat2)
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 6:
        m = int(input("Please enter the m of the matrix"))
        n = int(input("Please enter the n of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        try:
            print("The transpose of the matrix is")
            print(np.transpose(m1))
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 7:
        m = int(input("Please enter the order of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(m):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        try:
            print("The trace of the matrix is")
            print(np.trace(m1))
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 8:
        m = int(input("Please enter the order of the matrix of coefficients"))
        l1 = []
        constants = []
        m1 = None
        print("Please enter the data for matrix of coefficients")
        for i in range(m):
            row = []
            for j in range(m):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        print("Please enter the constants")
        for i in range(m):
            const = int(input("Please enter the constants"))
            constants.append(const)
        constants = np.array(constants)
        try:
            print("The solution of the system of linear equations is")
            print(np.linalg.solve(m1, constants))
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 9:
        m = int(input("Please enter the dimension of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(m):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        try:
            print("The determinant of the matrix is")
            print(np.linalg.det(m1))
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 10:
        m = int(input("Please enter the dimension of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(m):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        try:
            print("The inverse of the matrix is")
            print(np.linalg.inv(m1))
        except:
            print("An error has occurred please ensure the integrity of your input")

    elif menu_option == 11:
        m = int(input("Please enter the dimension of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(m):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        try:
            print("The SVD of the matrix is")
            print(np.linalg.svd(m1))
        except:
            print("An error has occurred please ensure the integrity of your input")
    elif menu_option == 12:
        m = int(input("Please enter the dimension of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(m):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        try:
            print("The eigen values of the matrix are")
            print(np.linalg.eigvals(m1))
        except:
            print("An error has occurred please ensure the integrity of your input")
    elif menu_option == 13:
        m = int(input("Please enter the m of the matrix"))
        n = int(input("Please enter the n of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(n):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        target = int(input("please enter the required number to search for in the matrix"))
        try:
            print("The search of the matrix is")
            print(np.where(m1 == target))
        except:
            print("An error has occurred please ensure the integrity of your input")
    elif menu_option == 14:
        m = int(input("Please enter the dimension of the matrix"))
        l1 = []
        m1 = None
        print("Please enter the data for matrix ")
        for i in range(m):
            row = []
            for j in range(m):
                element = int(input("Please enter the element"))
                row.append(element)
            l1.append(row)
        m1 = np.array(l1)
        try:
            print("The difference of the sum of the upper and lower triangular matrices are")
            print(np.sum(np.triu(m1)) - np.sum(np.tril(m1)))
        except:
            print("An error has occurred please ensure the integrity of your input")
    elif menu_option == 15:
        break
    else:
        print("please enter the correct menu option")
