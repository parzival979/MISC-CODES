/*Implement a character stack using Linked List. PUSH and POP operations should be clearly
defined. WAP to take a random string as user-input. String should be a combination of
alphabets and operators. Traverse through the string and do the following operations.
• If a consonant is encountered, PUSH to the stack.
• If a vowel is encountered, POP from the stack
• Show the content of the top of the stack after each operation*/
#include<stdio.h>
#include<stdlib.h>
struct linked_list{
    char data;
    struct linked_list *next_node;
};
struct stack_{
    struct linked_list *head;
};
void push(struct stack_ *stack,char data);
char pop(struct stack_ *stack);
int stack_empty(struct stack_ *stack);
char peek_(struct stack_ *stack);
int is_vowel(char character);
int main(void){
    printf("PLEASE ENTER THE SIZE OF THE STRING\n");
    int size;
    scanf("%d",&size);
    char *string_ = NULL;
    string_ = (char *)malloc(sizeof(char) * (size+1));
    printf("PLEASE ENTER THE STRING\n");
    scanf("%s",string_);
    struct stack_ *required_stack = malloc(sizeof(struct stack_));
    required_stack->head = NULL;
    for (int i = 0;*(string_ + i) != '\0'; ++i){
        if(!is_vowel(*(string_ + i))){
            push(required_stack,*(string_ + i));
        }
        else if(is_vowel(*(string_+i)) && !stack_empty(required_stack)){
            pop(required_stack);
        }
        if(!stack_empty(required_stack))
            printf("THE TOP OF THE STACK IS %c\n",peek_(required_stack));
        else
            printf("STACK EMPTY\n");
    }

}
void push(struct stack_ *stack,char data){
    struct linked_list *temp;
    temp = (struct linked_list*)malloc(sizeof(struct linked_list));
    if(!temp){
        printf("STACK OVERFLOW ERROR!\n");
        return;
    }
    temp->data = data;
    temp->next_node = stack->head;
    stack->head = temp;
}
char pop(struct stack_ *stack){
    char data;
    struct linked_list *temp;
    if(stack_empty(stack)){
        printf("STACK UNDERFLOW ERROR\n");
    }
    temp = stack->head;
    stack->head = stack->head->next_node;
    data = temp->data;
    free(temp);
    return data;
}
int stack_empty(struct stack_ *stack){
    return stack->head==NULL;
}
char peek_(struct stack_ *stack){
    if(stack_empty(stack)){
        printf("STACK EMPTY\n");
        exit(0);
    }
    return stack->head->data;
};
int is_vowel(char character){
    if(character=='a'||character=='e'||character=='i'||character=='o'||character=='u')
        return 1;
    else
        return 0;
};