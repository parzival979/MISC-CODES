# program to solve the travelling salesman problem using brute force and dynamic programming
# we take the input in the form of a matrix of distances between the cities

import itertools

# function for the brute force algorithmx
def brute_force(matrix, n):
    # we create a list of all the cities
    cities = [i for i in range(n)]
    # we create a list of all the possible permutations of the cities
    permutations = list(itertools.permutations(cities))
    # we create a list to store the distances of all the possible paths
    distances = []
    # we iterate over all the possible paths
    for path in permutations:
        # we create a variable to store the distance of the current path
        distance = 0
        # we iterate over all the cities in the current path
        for i in range(n - 1):
            # we add the distance between the current city and the next city to the total distance
            distance += matrix[path[i]][path[i + 1]]
        # we add the distance between the last city and the first city to the total distance
        distance += matrix[path[n - 1]][path[0]]
        # we add the distance of the current path to the list of distances
        distances.append(distance)
    # we return the minimum distance
    return min(distances)

# function for the dynamic programming algorithm using memoization technique
def dynamic_programming(matrix, n):
    # initialize the memoization table
    memo = [[-1 for i in range(1 << n)] for j in range(n)]
    # we return the minimum distance
    return tsp(matrix, 0, 1, memo)

# function to find the minimum distance
def tsp(matrix, i, mask, memo):
    # if the distance is already calculated, return it
    if memo[i][mask] != -1:
        return memo[i][mask]
    # if the distance is not already calculated, calculate it
    if mask == (1 << len(matrix)) - 1:
        return matrix[i][0]
    # initialize the minimum distance to infinity
    min_distance = float('inf')
    # iterate over all the cities
    for j in range(len(matrix)):
        # if the current city is not visited
        if (mask & (1 << j)) == 0:
            # find the distance between the current city and the next city
            distance = matrix[i][j] + tsp(matrix, j, mask | (1 << j), memo)
            # update the minimum distance
            min_distance = min(min_distance, distance)
    # store the minimum distance in the memoization table
    memo[i][mask] = min_distance
    # return the minimum distance
    return min_distance


n = 5
matrix = [[0, 12, 10, 19, 8], [12, 0, 3, 7, 6], [10, 3, 0, 2, 20], [19, 7, 2, 0, 4], [8, 6, 20, 4, 0]]

default = bool(int(input("Enter 0 for default matrix, 1 for custom matrix: ")))
if default:
    # taking input from the user the number of cities
    n = int(input("Enter the number of cities: "))

    # taking input from the user the distances between the cities
    print("Enter the distances between the cities in the form of a matrix seperated by spaces: ")
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    print()

# printing the matrix of distances
print("The matrix of distances is: ")
print(matrix)

# calling both the functions and displaying the time taken by each function
import time

start_time = time.time()
print("The minimum distance using brute force is: ", brute_force(matrix, n))
print("The time taken by brute force is: ", time.time() - start_time, "seconds")

start_time = time.time()
print("The minimum distance using dynamic programming is: ", dynamic_programming(matrix, n))
print("The time taken by dynamic programming is: ", time.time() - start_time, "seconds")
