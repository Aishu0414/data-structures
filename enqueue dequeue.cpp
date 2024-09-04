#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);

    // If queue is empty, new node is both front and rear
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    // Add the new node at the end of the queue and update rear
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->data;

    // Move front to the next node
    queue->front = queue->front->next;

    // If front becomes NULL, then rear must also be NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Queue after enqueuing 10, 20, 30, 40:\n");
    display(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printf("Queue after dequeue:\n");
    display(queue);

    return 0;
}
