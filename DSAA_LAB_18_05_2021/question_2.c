/*Create a two-way Linked List of N Fibonacci numbers. N should be given as user input.
WAP to delete the nodes in the two-way linked list based on a given GP series. The factor of
the GP series will be taken as an user input. (Ex: 1, 2, 4, 8, 16..... : Factor 2).*/
#include<stdio.h>
#include<stdlib.h>
struct double_linked_list{
    long long int fib;
    struct double_linked_list *next_ptr,*prev_ptr;
};
int main(void){
    printf("PLEASE ENTER THE NUMBER OF FIBONACCI NUMBERS IN THE LINKED LIST\n");
    int nos_;
    scanf("%d",&nos_);
    long long int fib_1 = 0,fib_2 = 1;
    struct double_linked_list *head_ptr,*previous_node_temp_ptr;
    head_ptr = (struct double_linked_list*)malloc(sizeof(struct double_linked_list));
    struct double_linked_list *current_node_ptr;
    current_node_ptr = head_ptr;
    for (int i = 0; i < nos_; ++i){
        if(i < 2){
            current_node_ptr->fib = fib_2;
            fib_1 = fib_2;
            fib_2 = current_node_ptr->fib;
            current_node_ptr->prev_ptr = NULL;
            current_node_ptr->next_ptr = (struct double_linked_list*)malloc(sizeof(struct double_linked_list));
            previous_node_temp_ptr = current_node_ptr;
            current_node_ptr = current_node_ptr->next_ptr;
        }
        else if(i < nos_ - 1){
            current_node_ptr->fib = fib_1 + fib_2;
            fib_1 = fib_2;
            fib_2 = current_node_ptr->fib;
            current_node_ptr->prev_ptr = previous_node_temp_ptr ;
            current_node_ptr->next_ptr = (struct double_linked_list*)malloc(sizeof(struct double_linked_list));
            previous_node_temp_ptr = current_node_ptr;
            current_node_ptr = current_node_ptr->next_ptr;
        }
        else if(i == nos_ - 1){
            current_node_ptr->fib = fib_1 + fib_2;
            fib_1 = fib_2;
            fib_2 = current_node_ptr->fib;
            current_node_ptr->prev_ptr = previous_node_temp_ptr ;
            current_node_ptr->next_ptr = NULL;
        }
    }
    printf("THE INITIAL DOUBLY LINKED LIST OF FIBONACCI NUMBERS IS\n");
    for (current_node_ptr = head_ptr;current_node_ptr != NULL;current_node_ptr = current_node_ptr->next_ptr){
        printf("%lld ",current_node_ptr->fib);
    }
    printf("\n");
    printf("PLEASE ENTER THE RATIO OF THE GP OF NUMBERED ELEMENTS TO BE DELETED IN EACH ITERATION IN THE LINKED LIST\n");
    int ratio_,number_ = 1;
    scanf("%d",&ratio_);
    struct double_linked_list *freeing_ptr;
        int counter_ = 1;
        for (current_node_ptr = head_ptr; current_node_ptr != NULL;) {
            if ( number_ == counter_ && counter_ == 1) {
                current_node_ptr->next_ptr->prev_ptr = NULL;
                head_ptr = current_node_ptr->next_ptr;
                freeing_ptr = current_node_ptr;
                current_node_ptr = current_node_ptr->next_ptr;
                free(freeing_ptr);
                number_ *= ratio_;
            }
            else if( number_ == counter_ && counter_ == 2) {
                current_node_ptr->next_ptr->prev_ptr = NULL;
                head_ptr = current_node_ptr->next_ptr;
                freeing_ptr = current_node_ptr;
                current_node_ptr = current_node_ptr->next_ptr;
                free(freeing_ptr);
                number_ *= ratio_;
            }
            else if (number_ == counter_ && counter_ != nos_) {
                current_node_ptr->next_ptr->prev_ptr = current_node_ptr->prev_ptr;
                current_node_ptr->prev_ptr->next_ptr = current_node_ptr->next_ptr;
                freeing_ptr = current_node_ptr;
                current_node_ptr = current_node_ptr->next_ptr;
                free(freeing_ptr);
                number_ *= ratio_;
            } else if (number_ == counter_ && counter_ == nos_) {
                current_node_ptr->prev_ptr->next_ptr = NULL;
                freeing_ptr = current_node_ptr;
                current_node_ptr = current_node_ptr->next_ptr;
                free(freeing_ptr);
                number_ *= ratio_;
            } else {
                current_node_ptr = current_node_ptr->next_ptr;
            }
            counter_ += 1;
        }
    printf("THE RESULTANT LIST IS\n");
    for (current_node_ptr = head_ptr;current_node_ptr != NULL;current_node_ptr = current_node_ptr->next_ptr){
        printf("%lld ",current_node_ptr->fib);
    }
    printf("\n");
    freeing_ptr = NULL;
    for (current_node_ptr = head_ptr;current_node_ptr != NULL;){
        freeing_ptr = current_node_ptr;
        current_node_ptr = current_node_ptr->next_ptr;
        free(freeing_ptr);
    }


}