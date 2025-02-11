# By Sravanth Chowdary Potluri CS20B1006
# 8 Puzzle Problem

from copy import deepcopy

initial_state = [[2,8,3],[1,6,4],[7,0,5]]
goal_state = [[1,2,3],[8,0,4],[7,6,5]]

# heuristic value return function for a given state giving the number of misplaced tiles
def heuristic_1(state):
    count = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0:
                if state[i][j] != goal_state[i][j]:
                    count += 1
    return count

# heuristic value return function for a given state giving the sum of manhattan distances of all tiles from their goal positions
def heuristic_2(state):
    count = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0:
                for k in range(3):
                    for l in range(3):
                        if state[i][j] == goal_state[k][l]:
                            count += abs(i-k) + abs(j-l)
    return count

# function to check if a given state is the goal state
def is_goal(state):
    if state == goal_state:
        return True
    return False


class state:
    pass
    def __init__(self,state_config,depth,heuristic):
        self.state_config = state_config
        self.depth = depth
        if heuristic == 1:
            self.heuristic_value = heuristic_1(state_config)
            self.total_cost1 = self.depth + self.heuristic_value
        else:
            self.heuristic_value = heuristic_2(state_config)
            self.total_cost2 = self.depth + self.heuristic_value





# function to check if a given state is already present in the open list
def is_present_open_list(state):
    for i in open_list:
        if i.state_config == state:
            return True
    return False

# function to check if a given state is already present in the closed list
def is_present_closed_list(state):
    for i in closed_list:
        if i.state_config == state:
            return True
    return False

# function to generate all possible states from a given state
def generate_states(state):
    i = 0
    j = 0
    for k in range(3):
        for l in range(3):
            if state.state_config[k][l] == 0:
                i = k
                j = l
    states = []
    if i-1 >= 0:
        temp = deepcopy(state.state_config)
        temp[i][j] = temp[i-1][j]
        temp[i-1][j] = 0
        states.append(temp)
    if i+1 <= 2:
        temp = deepcopy(state.state_config)
        temp[i][j] = temp[i+1][j]
        temp[i+1][j] = 0
        states.append(temp)
    if j-1 >= 0:
        temp = deepcopy(state.state_config)
        temp[i][j] = temp[i][j-1]
        temp[i][j-1] = 0
        states.append(temp)
    if j+1 <= 2:
        temp = deepcopy(state.state_config)
        temp[i][j] = temp[i][j+1]
        temp[i][j+1] = 0
        states.append(temp)
    return states

# displaying the time to complete the search
import time
start_time = time.time()

open_list = []
closed_list = []
open_list.append(state(initial_state,0,2))
n_nodes_visited = 0

while True:
    if len(open_list) == 0:
        print("No solution")
        break
    current_state = open_list.pop(0)
    n_nodes_visited += 1
    closed_list.append(current_state)
    if is_goal(current_state.state_config):
        print("Solution found Using Manhattan Distance Heuristic")
        print("Number of nodes visited",n_nodes_visited)
        print("Depth of the solution is",current_state.depth)
        print("Solution is")
        for i in current_state.state_config:
            print(i)
        break
    states = generate_states(current_state)
    for i in states:
        if not is_present_closed_list(i):
            if not is_present_open_list(i):
                open_list.append(state(i,current_state.depth+1,2))
            else:
                for j in open_list:
                    if j.state_config == i:
                        if j.depth > current_state.depth+1:
                            j.depth = current_state.depth+1
                            j.total_cost = j.depth + j.heuristic_value
    open_list.sort(key = lambda x: x.total_cost2)
    closed_list.sort(key = lambda x: x.total_cost2)



# displaying the time to complete the search
print("Time taken to complete the search is",time.time()-start_time)
print("")



# time to complete the search
import time
start_time = time.time()

open_list = []
closed_list = []
open_list.append(state(initial_state,0,1))
n_nodes_visited = 0

# loop to generate the solution
while True:
    if len(open_list) == 0:
        print("No solution")
        break
    current_state = open_list.pop(0)
    n_nodes_visited += 1
    closed_list.append(current_state)
    if is_goal(current_state.state_config):
        print("Solution found Using Misplaced Tiles Heuristic")
        print("Number of nodes visited",n_nodes_visited)
        print("Depth of the solution is",current_state.depth)
        print("Solution is")
        for i in current_state.state_config:
            print(i)
        break
    states = generate_states(current_state)
    for i in states:
        if not is_present_closed_list(i):
            if not is_present_open_list(i):
                open_list.append(state(i,current_state.depth+1,1))
            else:
                for j in open_list:
                    if j.state_config == i:
                        if j.depth > current_state.depth+1:
                            j.depth = current_state.depth+1
                            j.total_cost = j.depth + j.heuristic_value
    open_list.sort(key = lambda x: x.total_cost1)
    closed_list.sort(key = lambda x: x.total_cost1)



# displaying the time to complete the search
print("Time taken to complete the search is",time.time()-start_time)