#include <stdio.h>
void insert(int arr[], int *n, int pos, int value) {
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}
void deleteElement(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}
void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[100];  
    int n = 0;    
    int choice, pos, value;
    do {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &n, pos, value);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

