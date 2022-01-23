//QUESTION 3
/*Create a Linked List of N students. Each student node will have roll_no, percentage of
marks, and the corresponding grade. The roll_no will vary from 1 to N. Percentage of marks
will be taken as a random input */
// DECLARING THE REQUIRED STANDARD LIBRARIES
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// DECLARING THE STRUCTURE FOR LINKED LIST
struct linked_list{
    char grade;
    int perecentage_,roll_no;
    struct linked_list *node_ptr;
};
int main(void){
    // TAKING INPUT OF NUMBER OF STUDENTS
    printf("PLEASE ENTER THE NUMBER OF STUDENTS IN THE DATABASE\n");
    int nos_;
    scanf("%d",&nos_);
    struct linked_list *head_ =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *current_ptr =head_;
    srand(time(NULL));
    // ENTERING THE STUDENTS DETAILS INTO THE LINKED LIST
    for (int i = 0; i < nos_; ++i) {
        if(i < nos_-1){
            current_ptr->roll_no = i + 1;
            current_ptr->perecentage_ = 1 + rand()%100;
            if(current_ptr->perecentage_ >= 90)
                current_ptr->grade = 'A';
            else if(current_ptr->perecentage_ >= 80)
                current_ptr->grade = 'B';
            else if(current_ptr->perecentage_ >= 70)
                current_ptr->grade = 'C';
            else if(current_ptr->perecentage_ >= 60)
                current_ptr->grade = 'D';
            else if(current_ptr->perecentage_ >= 50)
                current_ptr->grade = 'E';
            else if(current_ptr->perecentage_ >= 35)
                current_ptr->grade = 'P';
            else
                current_ptr->grade = 'F';
            current_ptr->node_ptr = (struct linked_list*) malloc(sizeof(struct linked_list));
            current_ptr = current_ptr->node_ptr;
        }
        else{
            current_ptr->roll_no = i + 1;
            current_ptr->perecentage_ = 1 + rand()%100;
            if(current_ptr->perecentage_ >= 90)
                current_ptr->grade = 'A';
            else if(current_ptr->perecentage_ >= 80)
                current_ptr->grade = 'B';
            else if(current_ptr->perecentage_ >= 70)
                current_ptr->grade = 'C';
            else if(current_ptr->perecentage_ >= 60)
                current_ptr->grade = 'D';
            else if(current_ptr->perecentage_ >= 50)
                current_ptr->grade = 'E';
            else if(current_ptr->perecentage_ >= 35)
                current_ptr->grade = 'P';
            else
                current_ptr->grade = 'F';
            current_ptr->node_ptr = NULL;
        }
    }
    // PRINTING THE LIST OF STUDENTS WITHOUT GROUPING THEM
    printf("THE LIST OF STUDENTS IN UNGROUPED FORMAT IS\n");
    for (current_ptr = head_;current_ptr != NULL ;current_ptr = current_ptr->node_ptr){
        printf("ROLL NO:%d PERCENTAGE:%d GRADE:%c\n",current_ptr->roll_no,current_ptr->perecentage_,current_ptr->grade);
    }
    // CREATING LINKED LISTS TO GROUP STUDENTS BASED ON GRADE
    struct linked_list *head_a =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *head_b =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *head_c =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *head_d =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *head_e =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *head_p =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *head_f =(struct linked_list*) malloc(sizeof(struct linked_list));
    struct linked_list *current_ptr_a =head_a,*temp_pointer_a = NULL;
    struct linked_list *current_ptr_b =head_b,*temp_pointer_b = NULL;
    struct linked_list *current_ptr_c =head_c,*temp_pointer_c = NULL;
    struct linked_list *current_ptr_d =head_d,*temp_pointer_d = NULL;
    struct linked_list *current_ptr_e =head_e,*temp_pointer_e = NULL;
    struct linked_list *current_ptr_p =head_p,*temp_pointer_p = NULL;
    struct linked_list *current_ptr_f =head_f,*temp_pointer_f = NULL;
    int n_a=0,n_b=0,n_c=0,n_d=0,n_e=0,n_p=0,n_f=0;
    // GROUPING THE STUDENTS INTO DIFFERENT GROUPS
    for (current_ptr = head_;current_ptr != NULL ;current_ptr = current_ptr->node_ptr){
        if(current_ptr->grade == 'A') {
            n_a+=1;
            current_ptr_a->grade = current_ptr->grade;
            current_ptr_a->perecentage_ = current_ptr->perecentage_;
            current_ptr_a->roll_no = current_ptr->roll_no;
            current_ptr_a->node_ptr = (struct linked_list *) malloc(sizeof(struct linked_list));
            temp_pointer_a = current_ptr_a;
            current_ptr_a = current_ptr_a->node_ptr;
            continue;
        }
        else if(current_ptr->grade == 'B') {
            n_b+=1;
            current_ptr_b->grade = current_ptr->grade;
            current_ptr_b->perecentage_ = current_ptr->perecentage_;
            current_ptr_b->roll_no = current_ptr->roll_no;
            current_ptr_b->node_ptr = (struct linked_list*) malloc(sizeof(struct linked_list));
            temp_pointer_b = current_ptr_b;
            current_ptr_b = current_ptr_b->node_ptr;
            continue;
        }
        else if(current_ptr->grade == 'C') {
            n_c+=1;
            current_ptr_c->grade = current_ptr->grade;
            current_ptr_c->perecentage_ = current_ptr->perecentage_;
            current_ptr_c->roll_no = current_ptr->roll_no;
            current_ptr_c->node_ptr = (struct linked_list*) malloc(sizeof(struct linked_list));
            temp_pointer_c = current_ptr_c;
            current_ptr_c = current_ptr_c->node_ptr;
            continue;
        }
        else if(current_ptr->grade == 'D') {
            n_d+=1;
            current_ptr_d->grade = current_ptr->grade;
            current_ptr_d->perecentage_ = current_ptr->perecentage_;
            current_ptr_d->roll_no = current_ptr->roll_no;
            current_ptr_d->node_ptr = (struct linked_list*) malloc(sizeof(struct linked_list));
            temp_pointer_d = current_ptr_d;
            current_ptr_d = current_ptr_d->node_ptr;
            continue;
        }
        else if(current_ptr->grade == 'E') {
            n_e+=1;
            current_ptr_e->grade = current_ptr->grade;
            current_ptr_e->perecentage_ = current_ptr->perecentage_;
            current_ptr_e->roll_no = current_ptr->roll_no;
            current_ptr_e->node_ptr = (struct linked_list*) malloc(sizeof(struct linked_list));
            temp_pointer_e = current_ptr_e;
            current_ptr_e = current_ptr_e->node_ptr;
            continue;
        }
        else if(current_ptr->grade == 'P') {
            n_p+=1;
            current_ptr_p->grade = current_ptr->grade;
            current_ptr_p->perecentage_ = current_ptr->perecentage_;
            current_ptr_p->roll_no = current_ptr->roll_no;
            current_ptr_p->node_ptr = (struct linked_list*) malloc(sizeof(struct linked_list));
            temp_pointer_p = current_ptr_p;
            current_ptr_p = current_ptr_p->node_ptr;
            continue;
        }
        else if(current_ptr->grade == 'F'){
            n_f+=1;
            current_ptr_f->grade = current_ptr->grade;
            current_ptr_f->perecentage_ = current_ptr->perecentage_;
            current_ptr_f->roll_no = current_ptr->roll_no;
            current_ptr_f->node_ptr = (struct linked_list*) malloc(sizeof(struct linked_list));
            temp_pointer_f = current_ptr_f;
            current_ptr_f = current_ptr_f->node_ptr;
            continue;
        }

    }
    printf("HELLO\n");
    if(n_a > 0)
        temp_pointer_a->node_ptr = NULL;
    else
        head_a= NULL;
    if(n_b > 0)
        temp_pointer_b->node_ptr = NULL;
    else
        head_b= NULL;
    if(n_c > 0)
        temp_pointer_c->node_ptr = NULL;
    else
        head_c= NULL;
    if(n_d > 0)
        temp_pointer_d->node_ptr = NULL;
    else
        head_d = NULL;
    if(n_e > 0)
        temp_pointer_e->node_ptr = NULL;
    else
        head_e = NULL;
    if(n_p > 0)
        temp_pointer_p->node_ptr = NULL;
    else
        head_p= NULL;
    if(n_f > 0)
        temp_pointer_f->node_ptr = NULL;
    else
        head_f= NULL;
    /* FREEING THE UNUSED NODE OF THE LINKED LIST AND SETTING THE POINTER TO IT TO NULL*/
    printf("THE LIST OF STUDENTS IN GROUPED FORMAT IS\n");
    printf("GRADE A\n");
    for (current_ptr_a = head_a;current_ptr_a != NULL ;current_ptr_a = current_ptr_a->node_ptr){
        printf("ROLL NO:%d PERCENTAGE:%d GRADE:%c\n",current_ptr_a->roll_no,current_ptr_a->perecentage_,current_ptr_a->grade);
    }
    printf("GRADE B\n");
    for (current_ptr_b = head_b;current_ptr_b != NULL ;current_ptr_b = current_ptr_b->node_ptr){
        printf("ROLL NO:%d PERCENTAGE:%d GRADE:%c\n",current_ptr_b->roll_no,current_ptr_b->perecentage_,current_ptr_b->grade);
    }
    printf("GRADE C\n");
    for (current_ptr_c = head_c;current_ptr_c != NULL ;current_ptr_c = current_ptr_c->node_ptr){
        printf("ROLL NO:%d PERCENTAGE:%d GRADE:%c\n",current_ptr_c->roll_no,current_ptr_c->perecentage_,current_ptr_c->grade);
    }
    printf("GRADE D\n");
    for (current_ptr_d = head_d;current_ptr_d != NULL ;current_ptr_d = current_ptr_d->node_ptr){
        printf("ROLL NO:%d PERCENTAGE:%d GRADE:%c\n",current_ptr_d->roll_no,current_ptr_d->perecentage_,current_ptr_d->grade);
    }
    printf("GRADE E\n");
    for (current_ptr_e = head_e;current_ptr_e != NULL ;current_ptr_e = current_ptr_e->node_ptr){
        printf("ROLL NO:%d PERCENTAGE:%d GRADE:%c\n",current_ptr_e->roll_no,current_ptr_e->perecentage_,current_ptr_e->grade);
    }
    printf("GRADE P\n");
    for (current_ptr_p = head_p;current_ptr_p != NULL ;current_ptr_p = current_ptr_p->node_ptr){
        printf("ROLL NO:%d PERCENTAGE:%d GRADE:%c\n",current_ptr_p->roll_no,current_ptr_p->perecentage_,current_ptr_p->grade);
    }
    printf("GRADE F\n");
    for (current_ptr_f = head_f;current_ptr_f != NULL ;current_ptr_f = current_ptr_f->node_ptr){
        printf("ROLL NO:%d PERCENTAGE:%d GRADE:%c\n",current_ptr_f->roll_no,current_ptr_f->perecentage_,current_ptr_f->grade);
    }
    // FREEING ALL THE DATA USED THROUGH DYNAMIC MEMORY ALLOCATION
    struct linked_list *firstptr = head_;
    struct linked_list *secondptr;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    firstptr = head_a;
    secondptr = NULL;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    firstptr = head_b;
    secondptr = NULL;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    firstptr = head_c;
    secondptr = NULL;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    firstptr = head_d;
    secondptr = NULL;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    firstptr = head_e;
    secondptr = NULL;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    firstptr = head_p;
    secondptr = NULL;
    while (firstptr != NULL){
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }
    firstptr = head_f;
    secondptr = NULL;
    while (firstptr != NULL) {
        secondptr = firstptr->node_ptr;
        free(firstptr);
        firstptr = secondptr;
    }



}

