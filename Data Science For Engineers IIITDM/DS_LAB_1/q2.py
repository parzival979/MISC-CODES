# Data Science Lab 2 code 2 by Sravanth Chowdary Potluri

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

# boundary condition
if len(req_arr) == 0:
    exit(0)

# printing the entered array
print("The entered array is")
print(req_arr)

# printing the sorted array
req_arr.sort()
print("The sorted array is")
print(req_arr)

# taking the target number as input
target = int(input("please enter the required target number"))

# binary searching
low = 0
high = len(req_arr)-1
mid = (low+high)//2
while low <= high:
    if target == req_arr[mid]:
        print("Target found at index "+str(mid))
        exit(0)
    elif target > req_arr[mid]:
        low = mid+1
    elif target < req_arr[mid]:
        high = mid-1
    mid = (low + high) // 2

print("target not found")

