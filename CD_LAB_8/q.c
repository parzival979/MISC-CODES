//Programmed By Sravanth Chowdary Potluri CS20B1006
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct parsetree
{
    char c;
    struct parsetree *left;
    struct parsetree *right;
};
struct parsetree *newNode()
{
    struct parsetree *node = (struct parsetree *)malloc(sizeof(struct parsetree));
    node->c = ' ';
    node->left = NULL;
    node->right = NULL;

    return (node);
}
void printCurrentLevel(struct parsetree *root, int level, int h);
int height(struct parsetree *node);

/* Function to print level order traversal a tree*/
void printLevelOrder(struct parsetree *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        for (int j = 0; j < pow(2, h - 3) - i; j++)
            printf("  ");
        printCurrentLevel(root, i, h - i);
        printf("\n\n");
    }
}

/* Print nodes at a current level */
void printCurrentLevel(struct parsetree *root, int level, int h)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {

        printf("%c", root->c);
    }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1, h);
        printf("   ");
        printCurrentLevel(root->right, level - 1, h);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct parsetree *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

int main()
{
    char input[20];
    printf("Enter the Binary String:");
    scanf("%s", input);
    struct parsetree *head = newNode();
    struct parsetree *child1 = newNode();
    struct parsetree *child2 = newNode();
    head->c = 'S';
    head->left = child1;
    head->right = child2;
    child1->c = 'l';
    child2->c = 'l';
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '.')
        {
            break;
        }
        count++;
    }
    struct parsetree *temp = head->left;
    for (int i = count - 1; i >= 0; i--)
    {
        if (i > 0)
        {
            struct parsetree *c1 = newNode();
            struct parsetree *c2 = newNode();
            temp->left = c1;
            temp->right = c2;
            struct parsetree *value = newNode();
            c2->c = 'b';
            c2->right = NULL;
            c2->left = value;
            value->c = input[i];
            value->left = NULL;
            value->right = NULL;
            c1->c = 'l';
            temp = c1;
        }
        else
        {
            temp->right = NULL;
            struct parsetree *c2 = newNode();
            struct parsetree *value = newNode();
            temp->left = c2;
            c2->c = 'b';
            c2->left = value;
            c2->right = NULL;
            value->c = input[0];
            value->left = NULL;
            value->right = NULL;
        }
    }

    temp = head->right;
    int length = strlen(input);
    for (int i = count + 1; i < length; i++)
    {
        if (i != length - 1)
        {
            struct parsetree *c1 = newNode();
            struct parsetree *c2 = newNode();
            temp->left = c2;
            temp->right = c1;
            struct parsetree *value = newNode();
            c2->c = 'b';
            c2->right = NULL;
            c2->left = value;
            value->c = input[i];
            value->left = NULL;
            value->right = NULL;
            c1->c = 'l';
            temp = c1;
        }
        else
        {
            temp->right = NULL;
            struct parsetree *c2 = newNode();
            struct parsetree *value = newNode();
            temp->left = c2;
            c2->c = 'b';
            c2->left = value;
            c2->right = NULL;
            value->c = input[0];
            value->left = NULL;
            value->right = NULL;
        }
    }

    /* Function prototypes */

    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(head);

    double result = 0;
    for (int i = count; i > 0; i--)
    {
        if (input[count - i] == '1')
        {
            result += pow(2, i - 1);
        }
    }
    // printf("%lf", result);
    for (int i = count + 1; i < length; i++)
    {
        if (input[i] == '1')
        {
            result += pow(2, count - i);
        }
    }
    printf("\nResult: %lf\n", result);
}