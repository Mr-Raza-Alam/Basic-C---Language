#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 15

// Stack for holding operators
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char ch) {
    if (top == (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to get the precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else {
        return 0;
    }
}

// Function to check if the character is an operand
int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch); // operands are alphabetic or numeric
}

// Function to convert Infix to Postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch, topElement;

    while ((ch = infix[i++]) != '\0') {
        if (isOperand(ch)) {
            postfix[j++] = ch; // Directly add operand to postfix expression
        } else if (ch == '(') {
            push(ch); // Push '(' onto stack
        } else if (ch == ')') {
            // Pop until '(' is encountered
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop '(' from the stack
        } else {
            // Operator: pop operators from stack with higher or equal precedence
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch); // Push current operator onto stack
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin); // Read infix expression

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

 