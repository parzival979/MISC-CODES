/*Implement a Circular QUEUE using an array.*/
#include<stdio.h>
#include<stdlib.h>
struct queue{
    int front,rear;
    int capacity;
    int size;
    int *array;
};
void en_queue(struct queue *required_queue,int data);
int dequeue(struct queue *required_queue);
int main(void){
    printf("PLEASE ENTER THE CAPACITY OF THE QUEUE\n");
    int capacity;
    scanf("%d",&capacity);
    struct queue *required_queue =(struct queue*)malloc(sizeof(struct queue));
    required_queue->capacity = capacity;
    required_queue->size = 0;
    required_queue->front = required_queue->rear = -1;
    required_queue->array =(int*)malloc(capacity * sizeof(int));
    int menu_number = 0;
    do{
        printf("PLEASE ENTER 1 IF YOU WANT TO ADD AN ELEMENT INTO THE QUEUE\n");
        printf("PLEASE ENTER 2 IF YOU WANT TO REMOVE AN ELEMENT FROM THE END OF THE QUEUE\n");
        printf("PLEASE ENTER 0 IF YOU WANT TO EXIT\n");
        scanf("%d",&menu_number);
        int data = 0;
        switch(menu_number){
            case 1:
                printf("PLEASE ENTER THE DATA TO BE ENTERED INTO THE QUEUE\n");
                scanf("%d",&data);
                en_queue(required_queue,data);
                break;
            case 2:
                printf("THE REMOVED ELEMENT FROM THE QUEUE IS %d\n", dequeue(required_queue));
                break;
        }
        printf("THE SIZE OF THE QUEUE IS %d\n",required_queue->size);
    }while(menu_number != 0);
}
void en_queue(struct queue *required_queue,int data){
    if(required_queue->size == required_queue->capacity){
        printf("QUEUE OVERFLOW\n");
    }
    else{
        required_queue->rear = (required_queue->rear+1)%required_queue->capacity;
        required_queue->array[required_queue->rear] = data;
        if(required_queue->front == -1){
            required_queue->front = required_queue-> rear;
        }
        required_queue->size += 1;
    }
}
int dequeue(struct queue *required_queue){
    if(required_queue->size == 0){
        printf("QUEUE EMPTY\n");
        return INT_MIN;
    }
    int data = required_queue->array[required_queue->front];
    if(required_queue->front == required_queue->rear){
        required_queue->front = required_queue->rear = -1;
        required_queue->size = 0;
    }
    else{
        required_queue->front = (required_queue->front + 1)%required_queue->capacity;
        required_queue->size -= 1;
    }
    return data;
}


