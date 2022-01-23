/*
save the file as <roll_no.c>. Replace <roll_no> with your roll_no.
Once the coding part is complete, please upload the .c file in the google form: https://forms.gle/hXdup8ZGftcjLhbC6
Name: SRAVANTH CHOWDARY POTLURI
Roll No.: CS20B1006
Problem: Find the sum of the elements in the Right sub-tree without using recursion.

Use appropriate variable and function names. Comments should be added whenever necessary.
*/

// Include your header files
#include <stdio.h>
#include <stdlib.h>


// Write your structures
struct linked_list_node{
    struct binary_tree_node *data;
    struct linked_list_node *next_node;
};


struct queue{
    struct linked_list_node *front;
    struct linked_list_node *rear;
};

struct binary_tree_node{
    int data;
    struct binary_tree_node *left_node;
    struct binary_tree_node *right_node;

};



// Write your functions
struct binary_tree_node* create_node();
void in_order(struct binary_tree_node *root);
struct queue *create_queue(void);
int queue_empty(struct queue *queue);
void enqueue_queue(struct queue *queue,struct binary_tree_node *number);
struct binary_tree_node *dequeue_queue(struct queue *queue);
int sum(struct binary_tree_node *root);


int main()
{
	// Write your code
	struct binary_tree_node *root =create_node();
	root->data=1;
	root->left_node=create_node();
	root->left_node->data=3;
	root->left_node->left_node=NULL;
	root->left_node->right_node=create_node();
	root->left_node->right_node->data=9;
	root->left_node->right_node->left_node=NULL;
	root->left_node->right_node->right_node=create_node();
    root->left_node->right_node->right_node->data=2;
    root->left_node->right_node->right_node->left_node=NULL;
    root->left_node->right_node->right_node->right_node=NULL;
    root->right_node=create_node();
    root->right_node->data=10;
    root->right_node->left_node=create_node();
    root->right_node->left_node->data=14;
    root->right_node->left_node->left_node=NULL;
    root->right_node->left_node->right_node=NULL;
    root->right_node->right_node=create_node();
    root->right_node->right_node->data=13;
    root->right_node->right_node->left_node=create_node();
    root->right_node->right_node->left_node->data=0;
    root->right_node->right_node->left_node->left_node=NULL;
    root->right_node->right_node->left_node->right_node=NULL;
    root->right_node->right_node->right_node=create_node();
    root->right_node->right_node->right_node->data=7;
    root->right_node->right_node->right_node->left_node=NULL;
    root->right_node->right_node->right_node->right_node=NULL;
    printf("THE TREE INORDER TRAVERSAL IS\n");
    in_order(root);
    printf("\n");
    printf("THE SUM OF THE TREE IS\n");
    printf("%d\n", sum(root));
    printf("THE SUM OF THE LEFT SUB-TREE IS\n");
    printf("%d\n", sum(root->left_node));
    printf("THE SUM OF THE RIGHT SUB-TREE IS\n");
    printf("%d\n", sum(root->right_node));


	return 0;


}
struct binary_tree_node* create_node(){
    struct binary_tree_node *temp;
    temp = (struct binary_tree_node*) malloc(sizeof(struct binary_tree_node));
    return temp;
}
void in_order(struct binary_tree_node *root){
    if(root){
        in_order(root->left_node);
        printf("%d ",root->data);
        in_order(root->right_node);
    }
}
struct queue *create_queue(void){
    struct queue *queue =(struct queue*)malloc(sizeof(struct queue));
    if(!queue)
        return NULL;
    queue->front = queue->rear = NULL;
    return queue;
}

int queue_empty(struct queue *queue){
    if(queue->front == NULL && queue->rear == NULL)
        return 1;
    else
        return 0;

}

void enqueue_queue(struct queue *queue,struct binary_tree_node *number){
    struct linked_list_node *temp;
    temp =(struct linked_list_node*)malloc(sizeof(struct linked_list_node));
    temp->data = number;
    temp->next_node = NULL;
    if(queue_empty(queue)){
        queue->front = queue->rear = temp;
    }
    else{
        queue->rear->next_node = temp;
        queue->rear = temp;
    }
}

struct binary_tree_node *dequeue_queue(struct queue *queue){
    struct linked_list_node *temp;
    if(queue_empty(queue)){
        printf("QUEUE EMPTY\n");
        return NULL;
    }
    else{
        temp = queue->front;
        queue->front = queue->front->next_node;
        if(queue->front == NULL)
            queue->rear = NULL;
    }
    struct binary_tree_node *something = temp->data;
    free(temp);
    return(something);

}
int sum(struct binary_tree_node *root){
    struct binary_tree_node *temp;
    struct queue *required_queue=create_queue();
    if(!root)
        return -1;
    enqueue_queue(required_queue,root);
    int sum=0;
    while(!queue_empty(required_queue)){
        temp = dequeue_queue(required_queue);
        sum+=temp->data;
        if(temp->left_node)
            enqueue_queue(required_queue,temp->left_node);
        if(temp->right_node)
            enqueue_queue(required_queue,temp->right_node);

    }
    return sum;
}


