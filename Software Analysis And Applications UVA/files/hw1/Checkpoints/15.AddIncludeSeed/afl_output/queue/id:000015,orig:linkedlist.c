#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 42;
    head->next = NULL;
    printf("%d\n", head->data);
    free(head);
    return 0;
}