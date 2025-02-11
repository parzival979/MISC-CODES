# AI LAB END SEMSTER
# DNA SEQUENCE ALIGNMENT
# BY CS20B1006 Sravanth Chowdary Potluri

# importing heapq
import heapq

# Using Edit Distance Heuristic function to estimate the cost of reaching the goal state from current state
def heuristic_cost_estimate(seq1, seq2):
    # Initialize the edit distance to the absolute difference in sequence lengths
    edit_dist = abs(len(seq1) - len(seq2))

    # Loop over each character in the sequences and add to the edit distance
    for i in range(min(len(seq1), len(seq2))):
        if seq1[i] != seq2[i]:
            edit_dist += 1

    return edit_dist

# A* algorithm for finding the least alignment cost between two DNA sequences
def least_alignment_cost(seq1, seq2):
    # defining the open and closed sets
    open_set = []
    closed_set = set()

    # intializing the f and g scores to infinity
    g_score = {(i, j): float('inf') for i in range(len(seq1) + 1) for j in range(len(seq2) + 1)}
    f_score = {(i, j): float('inf') for i in range(len(seq1) + 1) for j in range(len(seq2) + 1)}

    # setting the initial g and f scores
    g_score[(0, 0)] = 0
    f_score[(0, 0)] = heuristic_cost_estimate(seq1[:0], seq2[:0])

    # adding the initial state to the open set
    heapq.heappush(open_set, (f_score[(0, 0)], (0, 0)))

    # while the open set is not empty we run the algorithm
    while open_set:
        # popping the state with the lowest f score
        current = heapq.heappop(open_set)[1]

        # if the current state is the goal state we return the g score
        if current == (len(seq1), len(seq2)):
            return g_score[current]

        # adding the current state to the closed set
        closed_set.add(current)

        # for each neighbor of the current state
        for neighbor in get_neighbors(seq1, seq2, current[0], current[1]):

            # calculating the tentative g score for the neighbor
            tentative_g_score = g_score[current] + neighbor_cost(neighbor, current, seq1, seq2)

            # if the neighbor is in the closed set we continue since we already visited it
            if neighbor in closed_set:
                continue

            # if the tentative g score is better than the previous g score we update the g score and f score
            if tentative_g_score < g_score[neighbor]:
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = tentative_g_score + heuristic_cost_estimate(seq1[:neighbor[0]], seq2[:neighbor[1]])

                # if the neighbor is not in the open set we add it
                if neighbor not in open_set:
                    heapq.heappush(open_set, (f_score[neighbor], neighbor))

    # return infinity if no path is found
    return float('inf')

# Helper function to generate all possible neighbor states
def get_neighbors(seq1, seq2, i, j):
    # for each neighbor we yield the neighbor state
    # the neighbors are the states that can be reached from the current state by inserting, deleting or substituting a character from seq1 or seq2
    for di, dj in [(1, 0), (0, 1), (1, 1)]:
        ni, nj = i + di, j + dj
        if ni <= len(seq1) and nj <= len(seq2):
            yield (ni, nj)
    if i < len(seq1):
        yield (i+1, j)
    if j < len(seq2):
        yield (i, j+1)


# Helper function to calculate the cost of transitioning from current state to neighbor state
def neighbor_cost(neighbor, current, seq1, seq2):
    i, j = neighbor
    if i == current[0] + 1 and j == current[1] + 1:
        return 0 if seq1[i-1] == seq2[j-1] else 1
    else:
        return 1


# taking the input from the user of the two DNA sequences
seq1 = input("Please enter the first sequence: ")
seq2 = input("Please enter the second sequence: ")

# printing the least alignment cost
print("The Least alignment cost is:", least_alignment_cost(seq1, seq2))