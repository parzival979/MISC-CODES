# Program by Sravanth Chowdary Potluri

# Node Class Definition
class node:
    def __init__(self, data):
        self.data = data
        self.next_node = None

# queue Class Definition
class queue:
    # init dunder method
    def __init__(self):
        self.head = None

    # enqueue method
    def enqueue(self, data):
        if self.head is None:
            self.head = node(data)
            return
        curptr = self.head
        while curptr.next_node is not None:
            curptr = curptr.next_node
        curptr.next_node = node(data)
    # dequeue method
    def dequeue(self):
        if not self.head:
            print("The queue is Empty")
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
            print("The queue is Empty")
            return None
        else:
            req_data = self.head.data
            return req_data
    # print method
    def print(self):
        if not self.head:
            print("The queue is Empty")
            return None
        else:
            cur_ptr = self.head
            print("the required queue is")
            while cur_ptr:
                print(cur_ptr.data)
                cur_ptr = cur_ptr.next_node

# required queue object
req_queue = queue()
# menu driven loop
while True:
    print("please enter the menu option 1.enqueue 2.dequeue 3.peek 4.print 5.exit")
    menu_option = int(input())
    # required menu options
    if menu_option == 1:
        data = int(input("please enter the data\n"))
        req_queue.enqueue(data)
    elif menu_option == 2:
        data = req_queue.dequeue()
        if data is not None:
            print("The dequeued data is " + str(data))
    elif menu_option == 3:
        data = req_queue.peek()
        if data is not None:
            print("The peek data is " + str(data))
    elif menu_option == 4:
        req_queue.print()
    elif menu_option == 5:
        exit(0)
    else:
        print("Wrong menu option entered")
