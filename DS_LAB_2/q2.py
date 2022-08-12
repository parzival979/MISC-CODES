list_of_sets = []
while True:
    print("please chose your option")
    print("""a.create an empty set
    b.insert
    c.delete
    d.search
    e.print
    f.union
    g.intersection
    h.set difference
    i.symmetric difference
    j.print all sets
    k.exit\n""")
    option = input()
    if option == 'a':
        list_of_sets.append(set())
        print('new empty set created')
    elif option == 'b':
        set_number = int(input("Please enter the set number in the list\n"))
        if not set_number < len(list_of_sets):
            print("the given set number does not exist")
            continue
        element = input("please enter the value to be entered into the set\n")
        list_of_sets[set_number].add(element)
    elif option == 'c':
        set_number = int(input("Please enter the set number in the list\n"))
        if not set_number < len(list_of_sets):
            print("the given set number does not exist")
            continue
        element = input("please enter the value to be deleted from the set\n")
        if element in list_of_sets[set_number]:
            list_of_sets[set_number].remove(element)
        else:
            print("the required element doesn't exist")
    elif option == 'd':
        set_number = int(input("Please enter the set number in the list\n"))
        if not set_number < len(list_of_sets):
            print("the given set number does not exist")
            continue
        element = input("please enter the value to be searched in the set\n")
        if element in list_of_sets[set_number]:
            print("the required element exist inside the set")
        else:
            print("the required element doesn't exist inside the set")
    elif option == 'e':
        set_number = int(input("Please enter the set number in the list\n"))
        if not set_number < len(list_of_sets):
            print("the given set number does not exist")
            continue
        print("the required set is")
        print(list_of_sets[set_number])
    elif option == 'f':
        num_1 = int(input("please enter the set number for union\n"))
        if not num_1 < len(list_of_sets):
            print("the given set number does not exist")
            continue
        num_2 = int(input("please enter the set number for union\n"))
        if not num_2 < len(list_of_sets):
            print("the given set number does not exist")
            continue
        print("the required union of the sets is")
        print(list_of_sets[num_1].union(list_of_sets[num_2]))
    elif option == 'g':
        num_1 = int(input("please enter the set number for intersection\n"))
        if not num_1 < len(list_of_sets):
            print("the given set number does not exist")
            continue
        num_2 = int(input("please enter the set number for intersection\n"))
        if not num_2 < len(list_of_sets):
            print("the given set number does not exist")
            continue
        print("the required intersection of the sets is")
        print(list_of_sets[num_1].intersection(list_of_sets[num_2]))
    elif option == 'h':
        num_1 = int(input("please enter the set number for difference\n"))
        if not num_1 < len(list_of_sets):
            print("the given set number does not exist")
            continue
        num_2 = int(input("please enter the set number for difference\n"))
        if not num_2 < len(list_of_sets):
            print("the given set number does not exist")
            continue
        print("the required difference of the sets is")
        print(list_of_sets[num_1].difference(list_of_sets[num_2]))
    elif option == 'i':
        num_1 = int(input("please enter the set number for symmetric difference\n"))
        if not num_1 < len(list_of_sets):
            print("the given set number does not exist")
            continue
        num_2 = int(input("please enter the set number for symmetric difference\n"))
        if not num_2 < len(list_of_sets):
            print("the given set number does not exist")
            continue
        print("the required symmetric difference of the sets is")
        print(list_of_sets[num_1].symmetric_difference(list_of_sets[num_2]))
    elif option == 'j':
        for i in list_of_sets:
            print(i)
    elif option == 'k':
        break
