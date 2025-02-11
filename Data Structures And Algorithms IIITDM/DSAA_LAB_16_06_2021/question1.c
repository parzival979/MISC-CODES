/*Create a doubly Linked List (Two-way Linked List) from the Calander month names (January,
February, March........December). Convert this to it's corresponding balanced Binary Search
Tree (BST). Perform the In-order traversal.*/
#include<stdio.h>
#include<stdlib.h>

//Structure for Doubly linked list node and tree node.
struct Node{
    char *month;
    struct Node *prev;
    struct Node *next;
};

struct Node* DLLToBSTRecur(struct Node **head_ref, int n);
struct Node* newnode(char *month){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->month = month;
    node->prev = NULL;
    node->next = NULL;
    return (node);
};

struct Node* DLLToBST(struct Node *head){
    return DLLToBSTRecur(&head, 12);
};

struct Node* DLLToBSTRecur(struct Node **head_ref, int n){
    // Base Case
    if (n <= 0)
        return NULL;
    // Recursively construct the left subtree
    struct Node *left = DLLToBSTRecur(head_ref, n/2);
    // Allocate memory for root, and link the above constructed left subtree with root
    struct Node *root = newnode((*head_ref)->month);
    root->prev = left;
    // Change head pointer of DLL for parent recursive calls
    *head_ref = (*head_ref)->next;
    // Recursively construct the right subtree and link it with root.
    // The number of nodes in right subtree  is total nodes - nodes in  left subtree - 1 (for root) which is n-n/2-1
    root->next = DLLToBSTRecur(head_ref, n-n/2-1);
    return root;
}

// Function Declarations
void Inorder(struct Node *root);

int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *current_node = NULL,*prev_node = NULL;
    current_node = head;
    for (int i = 0; i < 11; ++i) {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        current_node->next = temp;
        current_node->prev = prev_node;
        prev_node = current_node;
        current_node = current_node->next;
    }
    current_node->prev = prev_node;
    current_node->next = NULL;
    current_node = head;
    current_node->month = "january";
    current_node = current_node->next;
    current_node->month = "february";
    current_node = current_node->next;
    current_node->month = "march";
    current_node = current_node->next;
    current_node->month = "april";
    current_node = current_node->next;
    current_node->month = "may";
    current_node = current_node->next;
    current_node->month = "june";
    current_node = current_node->next;
    current_node->month = "july";
    current_node = current_node->next;
    current_node->month = "august";
    current_node = current_node->next;
    current_node->month = "september";
    current_node = current_node->next;
    current_node->month = "october";
    current_node = current_node->next;
    current_node->month = "november";
    current_node = current_node->next;
    current_node->month = "december";
    struct Node *root = DLLToBST(head);
    printf("The Inorder traversal of the Binary Search Tree is :\n");
    Inorder(root);
    printf("\n");
}

// Function Definitions
void Inorder(struct Node *root){
    if(root){
        Inorder(root->prev);
        printf("%s ", root->month);
        Inorder(root->next);
    }
}