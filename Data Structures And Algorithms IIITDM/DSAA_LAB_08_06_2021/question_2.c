/*Create a Complete Binary Tree made up of all the alphabets (A to Z) using Linked List. A is the
root of the tree. B and C will be the left and right children of A, respectively, and so on. Write
the recursive functions for Pre-Order, In-Order and Post-Order traversals to print the elements
in the Tree.*/
#include<stdio.h>
#include<stdlib.h>

struct tree_node{
    char data;
    struct tree_node *left,*right;
};

struct linked_list_node{
    struct tree_node *node_;
    struct linked_list_node *next_node;
};

struct queue{
    struct linked_list_node *front,*rear;
};

struct tree_node *new_node(char data);
void enqueue(struct queue *required_queue,struct tree_node *current_node);
void dequeue(struct queue *required_queue);
void insert_new_node(struct queue *required_queue,struct tree_node **root,char data);
void pre_order(struct tree_node *tree_head);
void in_order(struct tree_node *tree_head);
void post_order(struct tree_node *tree_head);


int main(void){
    struct tree_node *root = NULL;
    struct queue *required_queue = (struct queue *)malloc(sizeof(struct queue));
    required_queue->front = NULL;
    required_queue->rear = NULL;
    for (char i = 'A'; i <= 'Z'; ++i) {
        insert_new_node(required_queue,&root,i);
    }
    printf("PRE ORDER TRAVERSAL\n");
    pre_order(root);
    printf("\n");
    printf("POST ORDER TRAVERSAL\n");
    post_order(root);
    printf("\n");
    printf("IN ORDER TRAVERSAL\n");
    in_order(root);
    printf("\n");

}

struct tree_node *new_node(char data){
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
void insert_new_node(struct queue *required_queue,struct tree_node **root,char data){
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
void pre_order(struct tree_node *tree_head){
    if(tree_head){
        printf("%c ",tree_head->data);
        pre_order(tree_head->left);
        pre_order(tree_head->right);
    }
}
void in_order(struct tree_node *tree_head){
    if(tree_head){
        in_order(tree_head->left);
        printf("%c ",tree_head->data);
        in_order(tree_head->right);
    }
}
void post_order(struct tree_node *tree_head){
    if(tree_head){
        post_order(tree_head->left);
        post_order(tree_head->right);
        printf("%c ",tree_head->data);
    }
}




