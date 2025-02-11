# Program by Sravanth Chowdary Potluri

# Node Class Definition
class node:
    def __init__(self, data):
        self.data = data
        self.next_node = None

# Stack Class Definition


class stack:
    # init dunder method
    def __init__(self):
        self.head = None
    # push method
    def push(self, data):
        temp = self.head
        self.head = node(data)
        self.head.next_node = temp
    # pop method
    def pop(self):
        if not self.head:
            print("The Stack is Empty")
            return None
        else:
            req_ptr = self.head
            req_data = self.head.data
            del req_ptr
            self.head = self.head.next_node
            return req_data
    # peek method
    def peek(self):
        if not self.head:
            print("The Stack is Empty")
            return None
        else:
            req_data = self.head.data
            return req_data
    # print method
    def print(self):
        if not self.head:
            print("The Stack is Empty")
            return None
        else:
            cur_ptr = self.head
            print("the required stack is")
            while cur_ptr:
                print(cur_ptr.data)
                cur_ptr = cur_ptr.next_node

# required stack object
req_stack = stack()
# menu driven loop
while True:
    print("please enter the menu option 1.push 2.pop 3.peek 4.print 5.exit")
    menu_option = int(input())
    # required menu options
    if menu_option == 1:
        data = int(input("please enter the data\n"))
        req_stack.push(data)
    elif menu_option == 2:
        data = req_stack.pop()
        if data is not None:
            print("The popped data is " + str(data))
    elif menu_option == 3:
        data = req_stack.peek()
        if data is not None:
            print("The peek data is " + str(data))
    elif menu_option == 4:
        req_stack.print()
    elif menu_option == 5:
        exit(0)
    else:
        print("Wrong menu option entered")
