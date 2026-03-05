/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression*/
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

// push into stack
void push(char x) {
    top++;
    stack[top] = x;
}

// pop from stack
char pop() {
    return stack[top--];
}

// check precedence
int priority(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {

    char infix[100], postfix[100];
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {

        // if operand
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // if operator
        else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    // pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s", postfix);

    return 0;
}