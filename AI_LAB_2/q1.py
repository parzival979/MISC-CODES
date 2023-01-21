# Programmed By Sravanth Chowdary Potluri CS20B1006

# This program uses a recursive and iterative approach to solve the tower of hanoi problem.
# The recursive approach is a simple recursive function which calls itself to solve the problem.
def tower_of_hanoi_recursive(n, from_tower, to_tower, aux_tower):
    if n > 0:
        tower_of_hanoi_recursive(n - 1, from_tower, aux_tower, to_tower)
        print("Move disk", n, "from", from_tower, "to", to_tower)
        tower_of_hanoi_recursive(n - 1, aux_tower, to_tower, from_tower)

# the iterative approach makes use of a stack to implement the recursive functionality of the above function
def tower_of_hanoi_iterative(n, from_tower, to_tower, aux_tower):
    stack = []
    stack.append((n, from_tower, to_tower, aux_tower))
    while len(stack):
        temp = stack.pop()
        if temp[0] == "Print":
            print("Move disk", temp[1], "from", temp[2], "to", temp[3])
        else:
            if temp[0] > 0:
                stack.append((temp[0] - 1, temp[3], temp[2], temp[1]))
                stack.append(("Print", temp[0], temp[1], temp[2]))
                stack.append((temp[0] - 1, temp[1], temp[3], temp[2]))
            else:
                continue


tower_of_hanoi_iterative(3, "A", "C", "B")
print()
tower_of_hanoi_recursive(3, "A", "C", "B")
