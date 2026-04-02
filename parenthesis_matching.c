#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push
void push(char c) {
    stack[++top] = c;
}

// pop
char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

// check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !isMatchingPair(pop(), exp[i])) {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Balanced Expression\n");
    else
        printf("Not Balanced\n");

    return 0;
}