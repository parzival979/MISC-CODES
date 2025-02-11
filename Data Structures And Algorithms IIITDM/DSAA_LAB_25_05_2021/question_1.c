/*Implement an integer stack using Linked List. PUSH and POP operations should be clearly
defined. WAP to calculate the factorial of a number N using the above defined stack. The
number N should be taken as an user input*/
#include<stdio.h>
#include<stdlib.h>
struct linked_list{
    int data;
    struct linked_list *next_node;
};
struct stack_{
    struct linked_list *head;
};
void push(struct stack_ *stack,int data);
int pop(struct stack_ *stack);
int stack_empty(struct stack_ *stack);
int main(void){
    printf("PLEASE ENTER THE NUMBER YOU WANT TO KNOW THE FACTORIAL FOR\n");
    int number;
    scanf("%d",&number);
    long long int factorial = 1;
    if(number==0){
        printf("THE FACTORIAL IS 1\n");
        exit(0);
    }
    struct stack_ *factorial_stack =(struct stack_*)malloc(sizeof(struct stack_));
    factorial_stack->head = NULL;
    for (int i = 0; i < number; i++){
        push(factorial_stack,i+1);
    }
    while(!stack_empty(factorial_stack)){
        factorial *= pop(factorial_stack);
    }
    printf("THE REQUIRED FACTORIAL IS %lld",factorial);

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