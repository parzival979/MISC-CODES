//QUESTION 1
/*Create a Linked List of size N, where each node will have a random character and pointer to
the next node. N should be given as user input. WAP to remove the duplicate characters from
the list.*/
//DECLARING THE REQUIRED STANDARD LIBRARIES
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// STRUCTURE FOR THE LINKED LIST
struct linked_list{
    char character;
    struct linked_list *node_ptr;
};
int main(void){
    /* TAKING THE INPUT OF NUMBER OF CHARACTERS IN THE LINKED LIST*/
    printf("PLEASE ENTER THE NUMBER OF RANDOM CHARACTERS IN THE LINKED LIST\n");
    int nos_;
    scanf("%d",&nos_);
    struct linked_list *head_ =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *current_ptr =head_;
    srand(time(NULL));
    // FILLING THE LINKED LIST WITH RANDOM CHARACTERS
    for (int i = 0; i < nos_; ++i) {
        if(i<nos_-1){
            current_ptr->character = 65 + rand()%26;
            current_ptr->node_ptr =(struct linked_list*)malloc(sizeof(struct linked_list));
            current_ptr = current_ptr->node_ptr;
        }
        else if(i == nos_ - 1){
            current_ptr->character = 65 + rand()%26;
            current_ptr->node_ptr = NULL;
        }
    }
    // PRINTING THE RANDOMLY GENERATED LINKED LIST
    printf("THE RANDOMLY GENERATED LINKED LIST IS\n");
    for (current_ptr = head_;current_ptr!=NULL;current_ptr = current_ptr->node_ptr) {
        printf("%c ",current_ptr->character);
    }
    printf("\n");
    // CREATING AN ARRAY TO CHECK REPEATED LETTERS
    int *array =(int*)malloc(26*(sizeof(int)));
    for (int i = 0; i < 26; ++i) {
        *(array + i) = 0;
    }
    // DELETING REPEATED CHARACTERS
    struct linked_list *current_ptr_2,*freeing_ptr;
    for (current_ptr = head_;current_ptr!=NULL;){
        if(*(array +(current_ptr->character - 65)) == 0){
            *(array +(current_ptr->character - 65)) = 1;
            current_ptr_2 =current_ptr;
            current_ptr = current_ptr->node_ptr;
        }
        else{
            freeing_ptr = current_ptr->node_ptr;
            free(current_ptr);
            current_ptr_2->node_ptr =freeing_ptr;
            current_ptr =freeing_ptr;
        }
    }
    // PRINTING THE UPDATED LINKED LIST
    printf("THE LINKED LIST AFTER REMOVING DUPLICATE CHARACTERS IS\n");
    for (current_ptr = head_;current_ptr!=NULL ;current_ptr = current_ptr->node_ptr) {
        printf("%c ",current_ptr->character);
    }
    printf("\n");
    // FREEING THE USED MEMORY
    struct linked_list *firstptr = head_;
    struct linked_list *secondptr;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    free(array);

}