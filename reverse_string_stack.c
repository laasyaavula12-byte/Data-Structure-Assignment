#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push function
void push(char item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

// pop function
char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    // push all characters
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    for (int i = 0; i < len; i++) {
        printf("%c", pop());
    }

    return 0;
}