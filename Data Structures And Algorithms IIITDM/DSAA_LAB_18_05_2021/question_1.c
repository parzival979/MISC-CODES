/*Create a Linked List of size N, where each node will have a random floating point value and
pointer to the next node. WAP to reverse the linked list based on a given GP series. The
factor of the GP series will be taken as an user input. (Ex: 1, 2, 4, 8, 16..... : Factor 2).*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct linked_list{
    float data_;
    struct linked_list *next_node_ptr;
};
int main(void){
    printf("PLEASE ENTER THE NUMBER OF ELEMENTS IN THE LINKED LIST\n");
    int nos_;
    scanf("%d",&nos_);
    struct linked_list *head = NULL;
    head = malloc(sizeof(struct linked_list));
    struct linked_list *current_node_ptr = head;
    srand(time(NULL));
    for (int i = 0; i < nos_; ++i) {
        if(i < nos_ - 1){
            current_node_ptr->data_ = ((float)rand()/RAND_MAX)*(float)(10.0);
            current_node_ptr->next_node_ptr = malloc(sizeof(struct linked_list));
            current_node_ptr = current_node_ptr->next_node_ptr;
        }
        if(i == nos_-1){
            current_node_ptr->data_ = ((float)rand()/RAND_MAX)*(float)(10.0);
            current_node_ptr->next_node_ptr = NULL;
        }

    }
    printf("THE INITIAL ELEMENTS OF THE LINKED LIST ARE\n");
    for (current_node_ptr = head;current_node_ptr != NULL;current_node_ptr = current_node_ptr->next_node_ptr){
        printf("%f ",current_node_ptr->data_);
    }
    printf("\n");
    printf("PLEASE ENTER THE RATIO OF THE GP\n");
    int ratio_;
    scanf("%d",&ratio_);
    current_node_ptr = head;
    struct linked_list *temp_head = NULL,*traversal_ptr = NULL;
    int iteration = 1;
    for (int i = ratio_;current_node_ptr->next_node_ptr != NULL; i*=ratio_){
        temp_head = current_node_ptr->next_node_ptr;
        traversal_ptr = temp_head;
        int j = i;
        for (;j - 1>0 && traversal_ptr->next_node_ptr != NULL; j-=1) {
            traversal_ptr = traversal_ptr->next_node_ptr;
        }
        struct linked_list *temp_end_ptr= traversal_ptr->next_node_ptr;
        traversal_ptr->next_node_ptr= NULL;
        struct linked_list *next_ptr = NULL,*prev_ptr = NULL,*current_reversal_ptr = NULL;
        prev_ptr = temp_end_ptr;
        current_reversal_ptr = temp_head;
        while (current_reversal_ptr != NULL){
            next_ptr = current_reversal_ptr->next_node_ptr;
            current_reversal_ptr->next_node_ptr = prev_ptr;
            prev_ptr = current_reversal_ptr;
            current_reversal_ptr = next_ptr;
        }
        current_node_ptr->next_node_ptr = prev_ptr;
        current_node_ptr = temp_head;
        printf("ITERATION %d LIST\n",iteration);
        for (struct linked_list *current_node_ptr_1 = head;current_node_ptr_1 != NULL;current_node_ptr_1 = current_node_ptr_1->next_node_ptr){
            printf("%f ",current_node_ptr_1->data_);
        }
        printf("\n");
        iteration+=1;

    }
    printf("THE REQUIRED FINAL LINKED LIST IS\n");
    for (struct linked_list *current_node_ptr_1 = head;current_node_ptr_1 != NULL;current_node_ptr_1 = current_node_ptr_1->next_node_ptr){
        printf("%f ",current_node_ptr_1->data_);
    }
    printf("\n");
    struct linked_list *freeing_ptr = NULL;
    for (struct linked_list *current_node_ptr_1 = head;current_node_ptr_1 != NULL;current_node_ptr_1 = current_node_ptr_1->next_node_ptr){
       freeing_ptr = current_node_ptr_1;
       current_node_ptr_1 = current_node_ptr_1->next_node_ptr;
       free(freeing_ptr);
    }


}
