#include <iostream>
//CLASS FOR THE REQUIRED QUEUE
class queue{
private:
    //QUEUE VARIABLES
    int front=-1,rear=-1;
    int capacity=5;
    int size=0;
    int array[5];

public:
    //FUNCTION TO PRINT THE WHOLE QUEUE
    void display(){
        int i;
        for ( i = front; i != rear;i=((i+1)%capacity)) {
            std::cout<<array[i]<<" ";
        }
        if(i==rear){
            std::cout<<array[i]<<" ";
        }

        std::cout<<"\n";
    }
    //FUNCTION TO SEE THE FRONT ELEMENT OF THE QUEUE
    int peek(){
        return array[front];
    }
    //FUNCTION TO CHECK IF THE QUEUE IS FULL
    bool isFull(){
        return (capacity==size);
    }
    //FUNCTION TO CHECK IF THE QUEUE IS EMPTY
    bool isEmpty(){
        return(size==0);
    }
    //FUNCTION DECLARATIONS FOR ENQUEUE AND DEQUEUE OPERATIONS
    void enQueue(int data);
    int deQueue();

};
//ENQUEUE FUNCTION DEFINITION
void queue::enQueue(int data) {
    if(isFull())
        std::cout<<"QUEUE OVERFLOW\n";
    else{
        rear=(rear+1)%capacity;
        array[rear]=data;
        if(front==-1)
            front=rear;
        size+=1;
    }
}
//DEQUEUE FUNCTION DEFINITION
int queue::deQueue() {
    int data=INT_MIN;
    if(isEmpty()){
        std::cout<<"QUEUE IS EMPTY\n";
        return data;
    }
    data=array[front];
    if(front==rear){
        front=rear=-1;
        size=0;
    }
    else{
        front=(front+1)%capacity;
        size-=1;
    }
    return data;
}