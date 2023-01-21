#Programmed By Sravanth Chowdary Potluri CS20B1006

# this program uses a depth-first search algorithm, to explore different pouring scenarios, it checks if the state is already
# visited and if not it fill the jug1 from bucket, fill jug2 from bucket, empty jug1 to bucket, empty jug2 to bucket,
# pour jug1 to jug2, pour jug2 to jug1. It will stop when jug1 reaches the goal amount of water.

def jug_problem(jug1, jug2, bucket, goal):
    if jug1 == goal:
        return (jug1, jug2)
    if (jug1, jug2, bucket) in visited:
        return None
    visited.add((jug1, jug2, bucket))
    # fill jug1 from bucket
    if jug1 < 3 and bucket > 0:
        result = jug_problem(3, jug2, bucket - (3 - jug1), goal)
        if result:
            print("Fill jug1 from bucket")
            return result
    # fill jug2 from bucket
    if jug2 < 5 and bucket > 0:
        result = jug_problem(jug1, 5, bucket - (5 - jug2), goal)
        if result:
            print("Fill jug2 from bucket")
            return result
    # empty jug1 to bucket
    if jug1 > 0:
        result = jug_problem(0, jug2, bucket + jug1, goal)
        if result:
            print("Empty jug1 to bucket")
            return result
    # empty jug2 to bucket
    if jug2 > 0:
        result = jug_problem(jug1, 0, bucket + jug2, goal)
        if result:
            print("Empty jug2 to bucket")
            return result
    # pour jug1 to jug2
    if jug1 > 0 and jug2 < 5:
        amount = min(jug1, 5 - jug2)
        result = jug_problem(jug1 - amount, jug2 + amount, bucket, goal)
        if result:
            print(f"Pour {amount} liters from jug1 to jug2")
            return result
    # pour jug2 to jug1
    if jug2 > 0 and jug1 < 3:
        amount = min(jug2, 3 - jug1)
        result = jug_problem(jug1 + amount, jug2 - amount, bucket, goal)
        if result:
            print(f"Pour {amount} liters from jug2 to jug1")
            return result
    return None

visited = set()
print("Please Read The Print Statements in the reverse order as they appear")
print(jug_problem(0, 0, 8, 1))
# The output will be a tuple containing the final state of the two jugs, or None if the goal cannot be reached along
# with all the step taken to reach the solution.
