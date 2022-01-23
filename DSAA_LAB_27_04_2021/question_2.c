//QUESTION 2
/*Create a Linked List of N Fibonacci numbers. N should be given as user input. WAP to find
the summation of odd and even Fibonacci numbers in the series. The program should be run
in one pass (only one for/while loop in the entire program).*/
// DECLARING THE REQUIRED STANDARD LIBRARIES
#include<stdio.h>
#include<stdlib.h>
// STRUCTURE FOR LINKED LIST
struct linked_list{
    long long int fibonacci_of_node;
    struct linked_list *node_ptr;
};
int main(void){
    /*TAKING THE INPUT OF NUMBER OF FIBONACCI NUMBERS IN THE LINKED LIST*/
    printf("PLEASE ENTER THE NUMBER OF FIBONACCI NUMBERS YOU WANT IN YOUR LINKED LIST\n");
    int nos_;
    scanf("%d",&nos_);
    struct linked_list *head_ =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *current_ptr =head_;
    long long int fibonacci_1 = 0,fibonacci_2 =1;
    long long int sum_odd =0,sum_even =0;
    // ENTERING FIBONACCI NUMBERS INTO THE LINKED LIST
    printf("THE LIST OF FIBONACCI NUMBERS IS\n");
    for (int i = 0; i < nos_; ++i){
        if(i==0){
            current_ptr->fibonacci_of_node = fibonacci_1;
            printf("%lld ",current_ptr->fibonacci_of_node);
            current_ptr->node_ptr =(struct linked_list*)malloc(sizeof(struct linked_list));
            current_ptr = current_ptr->node_ptr;
        }
        else if(i==1){
            current_ptr->fibonacci_of_node = fibonacci_2;
            printf("%lld ",current_ptr->fibonacci_of_node);
            fibonacci_1 = fibonacci_1;
            fibonacci_2 = current_ptr->fibonacci_of_node;
            sum_odd += 1;
            current_ptr->node_ptr =(struct linked_list*)malloc(sizeof(struct linked_list));
            current_ptr = current_ptr->node_ptr;
        }
        else if(i < nos_-1){
            current_ptr->fibonacci_of_node = fibonacci_1 + fibonacci_2;
            printf("%lld ",current_ptr->fibonacci_of_node);
            fibonacci_1 = fibonacci_2;
            fibonacci_2 = current_ptr->fibonacci_of_node;
            if(current_ptr->fibonacci_of_node % 2 == 1){
                sum_odd += current_ptr->fibonacci_of_node;
            }
            else{
                sum_even += current_ptr->fibonacci_of_node;
            }
            current_ptr->node_ptr =(struct linked_list*)malloc(sizeof(struct linked_list));
            current_ptr = current_ptr->node_ptr;
        }
        else{
            current_ptr->fibonacci_of_node = fibonacci_1 + fibonacci_2;
            printf("%lld ",current_ptr->fibonacci_of_node);
            fibonacci_1 = fibonacci_2;
            fibonacci_2 = current_ptr->fibonacci_of_node;
            if(current_ptr->fibonacci_of_node % 2 == 1){
                sum_odd += current_ptr->fibonacci_of_node;
            }
            else{
                sum_even += current_ptr->fibonacci_of_node;
            }
            current_ptr->node_ptr = NULL;
        }
    }
    // FREEING THE USED DATA BY DYNAMIC MEMORY ALLOCATION
    struct linked_list *firstptr = head_;
    struct linked_list *secondptr;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    // PRINTING THE REQUIRED RESULT
    printf("\n");
    printf("THE SUM OF EVEN FIBONACCI AND ODD FIBONACCI NUMBERS ARE RESPECTIVELY %lld AND %lld\n",sum_even,sum_odd);

}