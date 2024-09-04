#include <stdio.h>
#include <stdlib.h>

// Node structure representing each element in the stack
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Heap overflow\n");
        return;
    }
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped_data = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from the stack.\n", popped_data);
    return popped_data;
}

// Function to display all elements in the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are:\n");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("None\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(stack);

    pop(&stack);

    display(stack);

    return 0;
}
