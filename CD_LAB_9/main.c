//Programmed By Sravanth Chowdary Potluri CS20B1006
// Given a boolean expression as an input, write a program to generate
// intermediate code for that boolean expression by using short circuit
// evaluation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **arr;
char *list;
int n = 1, m = 0;

void printer() {
    int i = 0;
    printf("\ntokens:\n");
    while (i < n - 1) {
        printf("%s\n", arr[i]);
        i++;
    }
    printf("\nsymbols:\n");
    printf("%s\n\n", list);
}

// function to split a<b<c into a<b&&b<c
void preParser(char *exp) {
    // loop through the expression
    int i = 0;
    char temp[100];
    while (i < strlen(exp)) {
        // printf("char: %c\n",exp[i]);
        // detect consequtive opearators
        if (exp[i] == '<' || exp[i] == '>') {
            if (i + 2 < strlen(exp)) {
                if (exp[i + 2] == '<' || exp[i + 2] == '>') {
                    // copy string following first opearator to temp
                    strcpy(temp, exp + i + 1);
                    // go to second opearator
                    i += 2;
                    // put null
                    exp[i] = '\0';
                    // concatenate && to the first opearator
                    strcat(exp, "&&");
                    // concatenate the rest of the string to the first opearator
                    strcat(exp, temp);
                    // print the new expression
                    printf("new: %s\n", exp);
                }
            }
        }
        i++;
    }
}

void parser(char *exp) {
    int i = 0, j = 0;
    char token[10];
    list = (char *)malloc(sizeof(char) * 20);
    printf("exp: %s\n", exp);
    while (exp[i] != '\0') {
        // printf("exp[i]=%c\n", exp[i]);
        if (exp[i] == '&' || exp[i] == '|') {
            // push symbol to list
            list[m] = exp[i];
            list[m + 1] = '\0';
            m++;
            // printf("list: %s\n", list);
            arr = (char **)realloc(arr, n * sizeof(char *));
            arr[n - 1] = (char *)malloc(strlen(token) * sizeof(char));
            strcpy(arr[n - 1], token);
            strcpy(arr[j], token);
            n++;
            j++;
            // printf("token: %s\n", token);
            token[0] = '\0';
            i++;
        } else {
            int k = strlen(token);
            token[k] = exp[i];
            token[k + 1] = '\0';
        }
        i++;
    }
    if (strlen(token) > 0) {
        arr = (char **)realloc(arr, n * sizeof(char *));
        arr[n - 1] = (char *)malloc(strlen(token) * sizeof(char));
        strcpy(arr[n - 1], token);
        strcpy(arr[j], token);
        n++;
        j++;
        token[0] = '\0';
    }
    printer();
}

char *postfixGenerator(char *exp) {
    char *postfix = (char *)malloc(sizeof(char) * strlen(exp));
    char *stack = (char *)malloc(sizeof(char) * strlen(exp));
    strcpy(stack, "");
    int counter = 0;
    //& has higher precedence over |
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '&' || exp[i] == '|') {
            // skip second opearator
            i++;
            // push counter to postfix
            postfix[strlen(postfix)] = counter + '0';
            counter++;
            // if stack empty
            if (strlen(stack) == 0) {
                stack[0] = exp[i];
                stack[1] = '\0';
            } else {
                if (stack[strlen(stack) - 1] == '|' && exp[i] == '&') {
                    stack[strlen(stack)] = exp[i];
                    stack[strlen(stack) + 1] = '\0';
                } else if (stack[strlen(stack) - 1] == '&' && exp[i] == '|') {
                    while (strlen(stack) > 0 &&
                           stack[strlen(stack) - 1] != '|') {
                        postfix[strlen(postfix)] = stack[strlen(stack) - 1];
                        postfix[strlen(postfix) + 1] = '\0';
                        stack[strlen(stack) - 1] = '\0';
                    }
                    // push operator to stack
                    stack[strlen(stack)] = exp[i];
                } else if (stack[strlen(stack) - 1] == '|' && exp[i] == '|') {
                    // push to stack
                    stack[strlen(stack)] = exp[i];
                    stack[strlen(stack) + 1] = '\0';
                } else if (stack[strlen(stack) - 1] == '&' && exp[i] == '&') {
                    // push to stack
                    stack[strlen(stack)] = exp[i];
                    stack[strlen(stack) + 1] = '\0';
                }
            }
        }
        printf("char: %c, postfix: %s, stack: %s\n", exp[i], postfix, stack);
    }
    // push final counter to postfix
    postfix[strlen(postfix)] = counter + '0';
    // pop all remaining stack to postfix
    while (strlen(stack) > 0) {
        postfix[strlen(postfix)] = stack[strlen(stack) - 1];
        postfix[strlen(postfix) + 1] = '\0';
        stack[strlen(stack) - 1] = '\0';
    }
    return postfix;
}

void intermediateGenerator() {
    int and = 1, or = m + 1;
    int i = 0;
    int counter = 0;
    printf("Intermediate code:\n");
    // printf("m is %d\n",m);
    while (i < strlen(list)) {
        // printf("now %s:\n", arr[i]);
        if (list[i] == '&') {
            if (counter == 0) {
                printf("if %s goto L%d\n", arr[i], and);
            } else {
                printf("L%d: if %s goto L%d\n", counter, arr[i], and);
            }
            and++;
            counter++;
            printf("goto L%d\n", and);
        } else {
            if (counter == 0) {
                printf("if %s goto L%d\n", arr[i], m-counter+1);
            } else {
                printf("L%d: if %s goto L%d\n", counter, arr[i], or);
                // counter++;
            }
            or --;
        }
        i++;
    }
    // printf final array element
    if (list[i - 1] == '&') {
        printf("L%d: if %s goto L%d\n", counter, arr[i], n);
        printf("L%d: %s\n", counter + 1, "T=0");
        and++;
        counter++;
    } else {
        if (counter == 0) {
            printf("if %s goto L%d\n", arr[i], n-2);
            printf("%s\n", "T=0");
        } else {
            printf("L%d: if %s goto L%d\n", counter + 1, arr[i], n);
            printf("%s\n", "T=0");
            or --;
        }
        if (counter != 0) {
            counter++;
        }
    }
    // setup remaining truths and falses
    printf("goto L%d\n", counter + 2);
    printf("L%d: %s\n", counter + 1, "T=1");
    printf("L%d: %s\n", counter + 2, "next code");
}

int main() {
    // get expression input
    char exp[100];
    char *postfix;
    printf("Enter the boolean expression: ");
    // parse input
    // scanf("%s",exp);
    // strcpy(exp, "a<b&&c<d||e<f");
    // strcpy(exp, "a<b||c<d&&e<f");
    // strcpy(exp, "a<b");
    strcpy(exp, "a<b&&e<f||c<d");
    //strcpy(exp, "a<b<c");
    preParser(exp);
    parser(exp);
    // postfix=postfixGenerator(exp);
    // printf("postfix: %s\n\n", postfix);
    intermediateGenerator();
}