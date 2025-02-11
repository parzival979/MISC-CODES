/*Implement a Parking Lot problem using a Header Linked List based QUEUE with the
following properties.
• Cars can enter from the REAR end and leave from the FRONT end. Cars are given
sequential integer tokens.
• The user should take input for the Parking Lot size (MAX size) at the beginning.
• The header node in the header linked list should be used to store the current QUEUE
size.
• While the cars enter to the QUEUE, if the current size exceeds the MAX size, it should
give an Overflow error - “Parking Lot FULL”.
• If a car from k-th location wants to leave, all the cars at the FRONT of the k-th car are
first removed and put into a STACK. Then, the k-th car is removed. Then, all the cars
from the STACK are popped out and again inserted at the FRONT of the queue.
• At every step, the header node value, FRONT and REAR need to be updated based on
the operation*/
#include <stdio.h>
#include <stdlib.h>
struct linked_list{
    int data;
    struct linked_list *next_node;
};
struct queue{
    struct linked_list *front;
    struct linked_list *rear;
};
struct stack_{
    struct linked_list *head;
};
void push(struct stack_ *stack,int data);
int pop(struct stack_ *stack);
int stack_empty(struct stack_ *stack);
void enter_parking_lot(struct linked_list *header_linked_list,int *token_number,struct queue *required_queue,int maximum_capacity);
void print_parking_lot(struct linked_list *header_linked_list);
int remove_parking_lot(struct linked_list *header_linked_list,int car_removal_number,struct queue *required_queue,int maximum_capacity);
int main(void){
    printf("PLEASE ENTER THE MAXIMUM SIZE OF THE PARKING LOT\n");
    int maximum_capacity;
    scanf("%d",&maximum_capacity);
    struct linked_list *header_linked_list;
    header_linked_list =(struct linked_list*)malloc(sizeof(struct linked_list));
    header_linked_list->next_node = NULL;
    header_linked_list->data = 0;
    struct queue *required_queue;
    required_queue =(struct queue*)malloc(sizeof(struct queue));
    int menu_option = 0;
    int *token_number;
    token_number = (int*)malloc(sizeof(int));
    *token_number = 0;
    int car_removal_number;
    do{
        printf("PLEASE ENTER 1 IF YOU WANT PARK A NEW CAR IN THE PARKING LOT\n");
        printf("PLEASE ENTER 2 IF YOU WANT TO REMOVE A CAR FROM THE PARKING LOT\n");
        printf("PLEASE ENTER 0 IF YOU WANT TO EXIT\n");
        scanf("%d",&menu_option);
        switch(menu_option){
            case 1:
                enter_parking_lot(header_linked_list,token_number,required_queue,maximum_capacity);
                break;
            case 2:
                printf("THE CARS IN THE PARKING LOT ARE\n");
                print_parking_lot(header_linked_list);
                printf("PLEASE ENTER THE NUMBER OF THE CAR FROM 1 TO %d WHICH YOU WANT TO REMOVE\n",header_linked_list->data);
                scanf("%d",&car_removal_number);
                remove_parking_lot(header_linked_list,car_removal_number,required_queue,maximum_capacity);
                break;
        }
        printf("THE CARS IN THE PARKING LOT ARE\n");
        print_parking_lot(header_linked_list);
    }while(menu_option != 0);
}
void push(struct stack_ *stack,int data){
    struct linked_list *temp;
    temp = (struct linked_list*)malloc(sizeof(struct linked_list));
    if(!temp){
        printf("STACK OVERFLOW ERROR!\n");
        return;
    }
    temp->data = data;
    temp->next_node = stack->head;
    stack->head = temp;
}
int pop(struct stack_ *stack){
    int data;
    struct linked_list *temp;
    if(stack_empty(stack)){
        printf("STACK UNDERFLOW ERROR\n");
        exit(0);
    }
    temp = stack->head;
    stack->head = stack->head->next_node;
    data = temp->data;
    free(temp);
    return data;
}
int stack_empty(struct stack_ *stack){
    return stack->head==NULL;
}
void enter_parking_lot(struct linked_list *header_linked_list,int *token_number,struct queue *required_queue,int maximum_capacity){
    if(header_linked_list->data == maximum_capacity){
        printf("PARKING LOT FULL\n");
        return;
    }
    *token_number += 1;
    header_linked_list->data += 1;
    if(header_linked_list->next_node == NULL){
        header_linked_list->next_node =(struct linked_list*)malloc(sizeof(struct linked_list));
        header_linked_list->next_node->data = *token_number;
        required_queue->front = header_linked_list->next_node;
        required_queue->rear = header_linked_list->next_node;
        required_queue->rear->next_node = NULL;
    }
    else{
        required_queue->rear->next_node =(struct linked_list*)malloc(sizeof(struct linked_list));
        required_queue->rear = required_queue->rear->next_node;
        required_queue->rear->data = *token_number;
        required_queue->rear->next_node = NULL;
    }
}
void print_parking_lot(struct linked_list *header_linked_list){
    struct linked_list *current_node_ptr = header_linked_list->next_node;
    while(current_node_ptr != NULL){
        printf("%d ",current_node_ptr->data);
        current_node_ptr = current_node_ptr->next_node;
    }
    printf("\n");
}
int remove_parking_lot(struct linked_list *header_linked_list,int car_removal_number,struct queue *required_queue,int maximum_capacity){
    if(header_linked_list->next_node == NULL){
        printf("PARKING LOT EMPTY\n");
        return -1;
    }
    else if(car_removal_number == 1){
        int data = header_linked_list->next_node->data;
        struct linked_list *temp;
        temp = required_queue->front->next_node;
        free(required_queue->front);
        header_linked_list->next_node = temp;
        required_queue->front = temp;
        header_linked_list->data -= 1;
        return data;
    }
    else if(car_removal_number == header_linked_list->data){
        struct stack_ *required_stack;
        required_stack =(struct stack_*)malloc(sizeof(struct stack_));
        required_stack->head = NULL;
        int temp_header_data = header_linked_list->data;
        for (int i = 1; i < car_removal_number; ++i){
            push(required_stack, remove_parking_lot(header_linked_list,1,required_queue,maximum_capacity));
        }
        remove_parking_lot(header_linked_list,1,required_queue,maximum_capacity);
        int data = pop(required_stack);
        header_linked_list->next_node = NULL;
        header_linked_list->next_node = (struct linked_list*)malloc(sizeof(struct linked_list));
        header_linked_list->next_node->data = data;
        required_queue->rear = header_linked_list->next_node;
        required_queue->rear->next_node = NULL;
        while(!stack_empty(required_stack)){
            data = pop(required_stack);
            struct linked_list *temp = header_linked_list->next_node;
            header_linked_list->next_node = NULL;
            header_linked_list->next_node = (struct linked_list*)malloc(sizeof(struct linked_list));
            header_linked_list->next_node->data = data;
            header_linked_list->next_node->next_node = temp;
            required_queue->front = header_linked_list->next_node;
        }
        header_linked_list->data = temp_header_data - 1;
        return -1;
    }
    else{
        struct stack_ *required_stack;
        required_stack =(struct stack_*)malloc(sizeof(struct stack_));
        required_stack->head = NULL;
        int temp_header_data = header_linked_list->data;
        for (int i = 1; i < car_removal_number; ++i){
            push(required_stack, remove_parking_lot(header_linked_list,1,required_queue,maximum_capacity));
        }
        remove_parking_lot(header_linked_list,1,required_queue,maximum_capacity);
        while(!stack_empty(required_stack)){
            int data = pop(required_stack);
            struct linked_list *temp = header_linked_list->next_node;
            header_linked_list->next_node = NULL;
            header_linked_list->next_node = (struct linked_list*)malloc(sizeof(struct linked_list));
            header_linked_list->next_node->data = data;
            header_linked_list->next_node->next_node = temp;
            required_queue->front = header_linked_list->next_node;
        }
        header_linked_list->data = temp_header_data - 1;
        return -1;

    }
}