#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char c) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = c;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Function to return the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i, k = 0;

    for (i = 0; infix[i]; i++) {
        // If the character is an operand, add it to the output
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        // If the character is '(', push it onto the stack
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        // If the character is ')', pop and output from the stack until '(' is encountered
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // Pop the '('
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(stack.arr[stack.top]) >= precedence(infix[i])) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0'; // Null-terminate the postfix expression
}

// Main function to test the infix to postfix conversion
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
