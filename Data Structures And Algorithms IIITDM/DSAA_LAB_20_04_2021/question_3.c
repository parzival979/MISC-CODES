// QUESTION 3
// DECLARING THE REQUIRED STANDARD LIBRARIES
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// CREATING THE STRUCTURE FOR THE LINKED LIST
struct linked_list{
    double data;
    struct linked_list *next_node_ptr;
};
int main(void){
    //CREATING THE INITIAL HEAD POINTER TO THE LINKED LIST AND ALLOCATING IT MEMORY
    struct linked_list *head = NULL;
    head = (struct linked_list*)malloc(sizeof(struct linked_list));
    // TAKING INPUT OF NUMBER OF ELEMENTS IN THE LINKED LIST
    printf("PLEASE ENTER THE NUMBER OF ELEMENTS OF THE LINKED LIST\n");
    int nos_;
    scanf("%d",&nos_);
    // CREATING A POINTER TO CREATE THE REQUIRED ELEMENTS OF THE LINKED LIST
    struct linked_list *current_ptr = head;
    // FOR LOOP TO CREATE AND STORE THE REQUIRED ELEMENTS OF THE LINKED LIST
    for (int i = 0; i < nos_; ++i){
        printf("PLEASE ENTER THE ELEMENT %d OF THE LINKED LIST\n",i+1);
        if(i < nos_-1) {
            scanf("%lf", &current_ptr->data);
            current_ptr->next_node_ptr = (struct linked_list *) malloc(sizeof(struct linked_list));
            current_ptr = current_ptr->next_node_ptr;
        }
        else{
            scanf("%lf", &current_ptr->data);
            current_ptr->next_node_ptr = NULL;
        }
    }
    // PRINTING THE ENTERED ELEMENTS OF THE LINKED LIST
    printf("THE ENTERED ELEMENTS ARE\n");
    for (current_ptr = head; current_ptr != NULL ;current_ptr = current_ptr->next_node_ptr){
        printf("%lf ",current_ptr->data);
    }
    printf("\n");
    // FINDING THE STANDARD DEVIATION AND VARIANCE OF THE ELEMENTS INSIDE THE LINKED LIST
    double mean=0,variance=0,standard_deviation=0;
    for (current_ptr = head; current_ptr != NULL ;current_ptr = current_ptr->next_node_ptr) {
        mean += (current_ptr->data)/nos_;
    }
    for (current_ptr = head; current_ptr != NULL ;current_ptr = current_ptr->next_node_ptr){
        variance += ((current_ptr->data - mean)*(current_ptr->data - mean))/(nos_-1);
    }
    // FREEING THE ALLOCATED MEMORY TO THE POINTER
    struct linked_list *firstptr = head;
    struct linked_list *secondptr;
    while (firstptr != NULL){
        secondptr = firstptr->next_node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    //PRINTING THE FINAL RESULT
    standard_deviation = sqrt(variance);
    printf("THE MEAN IS %lf AND THE STANDARD DEVIATION IS %lf\n",mean,standard_deviation);
}