#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
char peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

int precedence(char c) {
    if( c== '+' || c== '-' ) {
        return 1;
    } else if( c== '*' || c== '/' ) {
        return 2;
    } else if( c== '^' ) {
        return 3;
    }
    return 0;
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) { // Operand
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove the '(' from the stack
        } else { // Operator
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    gets(infix);
    infixToPostfix(infix);
    return 0;
}