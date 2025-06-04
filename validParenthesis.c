#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX 100

bool isValid(char* s) {
    int len = strlen(s);
    char stack[MAX];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) return false;
            char topChar = stack[top--];
            if ((s[i] == ')' && topChar != '(') ||
                (s[i] == '}' && topChar != '{') ||
                (s[i] == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return top == -1;
}
int main() {
    char s[MAX];
    printf("Enter a string of parentheses: ");
    scanf("%s", s);

    if (isValid(s)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is invalid.\n");
    }

    return 0;
}