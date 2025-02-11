# Data Science Lab 2 code 1 by Sravanth Chowdary Potluri

# initializing the required empty list
req_arr = []

# while loop to append the elements into the list
while True:
    continuity = int(input("Please enter 1 to enter a number into the array,any other number to stop\n"))
    if continuity == 1:
        number = int(input("Please enter the number to be inserted\n"))
        req_arr.append(number)
    else:
        break

# printing the entered array
print("The entered array is")
print(req_arr)

# sorting the array using insertion sort
for i in range(1, len(req_arr)):
    j = i
    while j >= 1:
        if req_arr[j] < req_arr[j-1]:
            # swapping the elements
            req_arr[j], req_arr[j-1] = req_arr[j-1], req_arr[j]
        else:
            break
        j -= 1

# printing the final sorted array
print("The final sorted array is")
print(req_arr)

