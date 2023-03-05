def max_cost(items_list, max_weight):
    remaining_weight = max_weight
    current_cost = 0
    # sorting the items list by cost/weight
    items_list.sort(key=lambda x: x[1]/x[0], reverse=True)
    for item in items_list:
        if item[0] <= remaining_weight:
            remaining_weight -= item[0]
            current_cost += item[1]
    return current_cost


items_list = []
max_weight = int(input("Enter the maximum weight of the bag: "))
num_items = int(input("Enter the number of items: "))
for i in range(num_items):
    weight = int(input("Enter the weight of item " + str(i+1) + ": "))
    cost = int(input("Enter the cost of item " + str(i+1) + ": "))
    items_list.append((weight, cost))
print("The list of items is: ", items_list)
print("The maximum cost is: ", max_cost(items_list, max_weight))

# Sample Input
# 400
# 5
# 10
# 1000
# 300
# 4000
# 1
# 5000
# 100
# 2000
# 200
# 5000