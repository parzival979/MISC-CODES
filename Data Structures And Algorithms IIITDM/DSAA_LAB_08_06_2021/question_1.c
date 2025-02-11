/*Create an integer Binary Tree (height>=3) of your choice using Linked List. Fill the integers
randomly. After creation of the Tree, Write the recursive functions for Pre-Order, In-Order and
Post-Order traversals. While traversing, find the Mean and Standard Deviation of the elements
in the tree.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct tree_node{
    int data;
    struct tree_node *left,*right;
};

struct linked_list_node{
    struct tree_node *node_;
    struct linked_list_node *next_node;
};

struct queue{
    struct linked_list_node *front,*rear;
};

struct tree_node *new_node(int data);
void enqueue(struct queue *required_queue,struct tree_node *current_node);
void dequeue(struct queue *required_queue);
void insert_new_node(struct queue *required_queue,struct tree_node **root,int data);
void pre_order(struct tree_node *tree_head,int *number_of_elements,int *sum_,int *sum_squares);
void in_order(struct tree_node *tree_head,int *number_of_elements,int *sum_,int *sum_squares);
void post_order(struct tree_node *tree_head,int *number_of_elements,int *sum_,int *sum_squares);


int main(void){
    int number_of_nodes;
    printf("PLEASE ENTER THE NUMBER OF RANDOM NUMBERED NODES\n");
    scanf("%d",&number_of_nodes);
    struct tree_node *root = NULL;
    struct queue *required_queue = (struct queue *)malloc(sizeof(struct queue));
    required_queue->front = NULL;
    required_queue->rear = NULL;
    srand(time(NULL));
    for (int i = 0; i < number_of_nodes; ++i) {
        insert_new_node(required_queue,&root,rand()%100);
    }
    int *number_of_elements,*sum_,*sum_squares;
    number_of_elements =(int *)malloc(sizeof(int));
    sum_ = (int *)malloc(sizeof(int));
    sum_squares = (int *)malloc(sizeof(int));
    *number_of_elements = 0;
    *sum_squares = 0;
    *sum_ = 0;
    printf("PRE ORDER TRAVERSAL\n");
    pre_order(root,number_of_elements,sum_,sum_squares);
    float mean = (float)*sum_/(float)*number_of_elements;
    float standard_deviation = sqrt((double)((*sum_squares/(*number_of_elements))-(mean*mean)));
    printf("\n");
    printf("PRE ORDER TRAVERSAL MEAN:- %f STANDARD DEVIATION:- %f",mean,standard_deviation);
    printf("\n");
    *number_of_elements = 0;
    *sum_squares = 0;
    *sum_ = 0;
    printf("POST ORDER TRAVERSAL\n");
    post_order(root,number_of_elements,sum_,sum_squares);
    mean = (float)*sum_/(float)*number_of_elements;
    standard_deviation = sqrt((double)((*sum_squares/(*number_of_elements))-(mean*mean)));
    printf("\n");
    printf("POST ORDER TRAVERSAL MEAN:- %f STANDARD DEVIATION:- %f",mean,standard_deviation);
    printf("\n");
    *number_of_elements = 0;
    *sum_squares = 0;
    *sum_ = 0;
    printf("IN ORDER TRAVERSAL\n");
    in_order(root,number_of_elements,sum_,sum_squares);
    mean = (float)*sum_/(float)*number_of_elements;
    standard_deviation = sqrt((double)((*sum_squares/(*number_of_elements))-(mean*mean)));
    printf("\n");
    printf("IN ORDER TRAVERSAL MEAN:- %f STANDARD DEVIATION:- %f",mean,standard_deviation);
    printf("\n");

}

struct tree_node *new_node(int data){
    struct tree_node *temp = (struct tree_node *)malloc(sizeof(struct tree_node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void enqueue(struct queue *required_queue,struct tree_node *current_node){
    struct linked_list_node *temp = (struct linked_list_node *)malloc(sizeof(struct linked_list_node));
    temp->node_ = current_node;
    temp->next_node = NULL;
    if(required_queue->rear == NULL){
        required_queue->rear = required_queue->front =  temp;
    }
    else{
        required_queue->rear->next_node = temp;
        required_queue->rear = temp;
    }
}

void dequeue(struct queue *required_queue){
    struct linked_list_node *temp;
    if(required_queue->front == NULL){
        return;
    }
    else{
        temp = required_queue->front;
        required_queue->front = required_queue->front->next_node;
        if(required_queue->front == NULL){
            required_queue->rear = NULL;
        }
    }
    free(temp);
}
void insert_new_node(struct queue *required_queue,struct tree_node **root,int data){
    struct tree_node *temp_node = new_node(data);
    if(!*root){
        *root =temp_node;
    }
    else{
        struct tree_node *front_node = required_queue->front->node_;
        if(!front_node->left){
            front_node->left = temp_node;
        }
        else if(!front_node->right){
            front_node->right = temp_node;
        }
        if(front_node->left && front_node->right){
            dequeue(required_queue);
        }

    }
    enqueue(required_queue,temp_node);
}
void pre_order(struct tree_node *tree_head,int *number_of_elements,int *sum_,int *sum_squares){
    if(tree_head){
        printf("%d ",tree_head->data);
        *number_of_elements += 1;
        *sum_ += tree_head->data;
        *sum_squares += (tree_head->data) * (tree_head->data);
        pre_order(tree_head->left,number_of_elements,sum_,sum_squares);
        pre_order(tree_head->right,number_of_elements,sum_,sum_squares);
    }
}
void in_order(struct tree_node *tree_head,int *number_of_elements,int *sum_,int *sum_squares){
    if(tree_head){
        in_order(tree_head->left,number_of_elements,sum_,sum_squares);
        printf("%d ",tree_head->data);
        *number_of_elements += 1;
        *sum_ += tree_head->data;
        *sum_squares += (tree_head->data) * (tree_head->data);
        in_order(tree_head->right,number_of_elements,sum_,sum_squares);
    }
}
void post_order(struct tree_node *tree_head,int *number_of_elements,int *sum_,int *sum_squares){
    if(tree_head){
        post_order(tree_head->left,number_of_elements,sum_,sum_squares);
        post_order(tree_head->right,number_of_elements,sum_,sum_squares);
        printf("%d ",tree_head->data);
        *number_of_elements += 1;
        *sum_ += tree_head->data;
        *sum_squares += (tree_head->data) * (tree_head->data);
    }
}




