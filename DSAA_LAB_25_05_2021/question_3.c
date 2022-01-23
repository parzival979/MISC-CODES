/*Evaluation of a Prefix expression using stack. Your program should do the following.
• User should take an infix expression as input
• WAP to convert this infix expression to Prefix expression
• WAP to evaluate the above Prefix expression using stack.*/
#include<stdio.h>
#include<stdlib.h>
struct linked_list{
    char data;
    struct linked_list *next_node;
};
struct stack_{
    struct linked_list *head;
};
struct stack_int{
    struct linked_list_int *head;
};
struct linked_list_int{
    int data;
    struct linked_list_int *next_node;
};
void push(struct stack_ *stack,char data);
char pop(struct stack_ *stack);
int stack_empty(struct stack_ *stack);
char peek_(struct stack_ *stack);
int Precedence(char ch);
int is_operator(char ch);
int size_of_string(char *ptr);
char *string_reversal(char *string,int size);
char *infix_to_reverse_prefix(char *reversed_infix);
int prefix_evaluator(char *prefix_);
void push_int(struct stack_int *stack,int data);
char pop_int(struct stack_int *stack);
int peek_int(struct stack_int *stack);
int stack_empty_int(struct stack_int *stack);
int main(void){
    printf("PLEASE ENTER YOUR INFIX EXPRESSION\n");
    char *infix_ =(char*)malloc(100 * sizeof(char));
    scanf("%s",infix_);
    printf("\n");
    int size_infix = size_of_string(infix_);
    char *reversed_infix_ = string_reversal(infix_,size_infix);
    char *reverse_prefix = infix_to_reverse_prefix(reversed_infix_);
    char *prefix = string_reversal(reverse_prefix, size_of_string(reverse_prefix));
    printf("THE REQUIRED PREFIX NOTATION IS\n");
    printf("%s\n",prefix);
    printf("THE REQUIRED RESULT OF THE EXPRESSION IS\n");
    printf("%d", prefix_evaluator(prefix));
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
int Precedence(char ch){
    switch (ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
};
int is_operator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')'){
        return 1;
    }
    return 0;
}
int size_of_string(char *ptr){
    int size;
    for (int i = 0;*(ptr + i) != '\0' ; ++i){
        size = i;
    }
    return size + 1;

};
char *string_reversal(char *string,int size){
    char *reversed_string =(char*)malloc(100 * sizeof(char));
    *(reversed_string + size) = '\0';
    for (int i = 0; i < size; ++i){
        if(*(string + i) == '(')
            *(reversed_string + size - i - 1) = ')';
        else if(*(string + i) == ')')
            *(reversed_string + size - i - 1) = '(';
        else
            *(reversed_string + size - i - 1) = *(string + i);

    }
    return reversed_string;

};
char *infix_to_reverse_prefix(char *reversed_infix){
    char *reverse_prefix = (char*)malloc(sizeof(size_of_string(reversed_infix)*sizeof(char)));
    struct stack_ *required_stack =(struct stack_*)malloc(sizeof(struct stack_));
    required_stack->head =NULL;
    int i,k;
    for (i = 0, k = -1;*(reversed_infix + i) != '\0';++i){
        if(!is_operator(*(reversed_infix+i)))
            *(reverse_prefix + (++k)) = *(reversed_infix + i);
        else if(*(reversed_infix + i) == '(')
            push(required_stack,*(reversed_infix + i));
        else if(*(reversed_infix + i) == ')'){
            while(!stack_empty(required_stack) && peek_(required_stack) != '(')
                *(reverse_prefix + (++k)) = pop(required_stack);
            pop(required_stack);
        }
        else{
            if(*(reversed_infix + i) == '^'){
                while(!stack_empty(required_stack) && Precedence(*(reversed_infix + i)) <= Precedence(peek_(required_stack)))
                    *(reverse_prefix + (++k)) = pop(required_stack);

            }
            else{
                while(!stack_empty(required_stack) && Precedence(*(reversed_infix + i)) < Precedence(peek_(required_stack)))
                    *(reverse_prefix + (++k)) = pop(required_stack);

            }
            push(required_stack,*(reversed_infix + i));
        }


    }
    while(!stack_empty(required_stack))
        *(reverse_prefix + (++k)) = pop(required_stack);
    *(reverse_prefix + (++k)) = '\0';
    return reverse_prefix;
};
int prefix_evaluator(char *prefix_){
    struct stack_int *required_stack =(struct stack_int*)malloc(sizeof(struct stack_int));
    required_stack->head =NULL;
    int size = size_of_string(prefix_);
    while (size != 0){
        if(!is_operator(*(prefix_ + size - 1)))
            push_int(required_stack,*(prefix_ + size - 1)-48);
        else{
            int a,b,result = 1;
            b = pop_int(required_stack);
            a = pop_int(required_stack);
            if(*(prefix_ + size - 1) == '+')
                result = b+a;
            else if(*(prefix_ + size - 1) == '-')
                result = b-a;
            else if(*(prefix_ + size - 1) == '*')
                result = b*a;
            else if(*(prefix_ + size - 1) == '/')
                result = b/a;
            else if(*(prefix_ + size - 1) == '^'){
                for (int i = 0; i < a; ++i) {
                    result *= b;
                }
            }
            push_int(required_stack,result);


        }
        size -= 1;
    }
    return peek_int(required_stack);

};
void push_int(struct stack_int *stack,int data){
    struct linked_list_int *temp;
    temp = (struct linked_list_int*)malloc(sizeof(struct linked_list_int));
    if(!temp){
        printf("STACK OVERFLOW ERROR!\n");
        return;
    }
    temp->data = data;
    temp->next_node = stack->head;
    stack->head = temp;
}
char pop_int(struct stack_int *stack){
    int data;
    struct linked_list_int *temp;
    if(stack_empty_int(stack)){
        printf("STACK UNDERFLOW ERROR\n");
    }
    temp = stack->head;
    stack->head = stack->head->next_node;
    data = temp->data;
    free(temp);
    return data;
}
int peek_int(struct stack_int *stack){
    if(stack_empty_int(stack)){
        printf("STACK EMPTY\n");
        exit(0);
    }
    return stack->head->data;
};
int stack_empty_int(struct stack_int *stack){
    return stack->head==NULL;
}