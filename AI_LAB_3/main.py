# This program solves the Travelling Salesman Problem using three search algorithms: DFS, BFS, and IDS.
# The TSP involves finding the shortest route that visits every city once and returns to the starting city.
# programmed By Sravanth Chowdary Potluri CS20B1006
n = 0
visited = []
costs = []

# BFS helper function to find total cost of the path
def distance(path, graph):
    result = 0
    if(len(path) == 1):
        return result
    else:
        for i in range(len(path) - 1):
            result += graph[path[i]][path[i + 1]]
    return result

# BFS function to find the minimum cost of the TSP
def bfs(graph):
    global n
    min_cost = 10**20
    best_route = []
    path = [0]
    queue = [(0, path)]
    while queue:
        # get front element in queue
        (curr, path) = queue.pop(0)
        # check for all nodes
        for i in range(n):
            # node not visited and path exists between nodes
            if graph[curr][i]:
                # path complete and best path
                if len(path) == n and i == 0:
                    temp = path + [i]
                    temp_dist = distance(temp, graph)
                    if temp_dist < min_cost:
                        min_cost = temp_dist
                        best_route = temp
                # path not complete and node not visited
                elif i not in path:
                    queue.append((i, path + [i]))
    print("The minimum cost of TSP using BFS is: " + str(min_cost))
    print("The best route using BFS is: " + str(best_route))


# DFS function to find the minimum cost of the TSP
def dfs(graph, curr, count, cost):
    global n, visited, costs
    # base case: all nodes visited and path complete
    if count == n and graph[curr][0]:
        costs.append(cost + graph[curr][0])
        return
    # recursive case: check for all nodes
    for i in range(n):
        if not visited[i] and graph[curr][i]:
            visited[i] = True
            dfs(graph, i, count + 1, cost + graph[curr][i])
            visited[i] = False



# IDS helper function
def ids_helper(graph, curr, count, cost, limit):
    global n, visited, costs
    # Check if all nodes have been visited and the path is complete
    if count == n and graph[curr][0]:
        costs.append(cost + graph[curr][0])
        return

    # Check if the depth limit has been reached
    if limit <= 0:
        return

    # Recursively check all nodes
    for i in range(n):
        # Check if the node has not been visited and there is a path between the nodes
        if not visited[i] and graph[curr][i]:
            visited[i] = True
            ids_helper(graph, i, count + 1, cost + graph[curr][i], limit - 1)
            visited[i] = False


# IDS function to find the minimum cost of the TSP
def ids(graph):
    global n
    for i in range(n):
        ids_helper(graph, 0, 1, 0, i)


# Main function
def main():
    global n, visited, costs
    # Get the number of nodes and the distance matrix
    print("Enter the number of nodes: ")
    n = int(input())
    dist = [[0 for i in range(n)] for i in range(n)]
    print("Enter the distance matrix: ")
    for i in range(n):
        dist[i] = list(map(int, input().split()))
    visited = [False for i in range(n)]
    visited[0] = True
    dfs(dist, 0, 1, 0)
    print("The minimum cost of TSP using DFS is: " + str(min(costs)))
    bfs(dist)
    costs = []
    visited = [False for i in range(n)]
    visited[0] = True
    ids(dist)
    print("The minimum cost of TSP using IDS is: " + str(min(costs)))


if __name__ == "__main__":
    main()
