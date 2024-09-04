#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Return the index if the target is found
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int n, target, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Perform linear search
    result = linearSearch(arr, n, target);

    // Output the result
    if (result != -1) {
        printf("Number %d found at index %d.\n", target, result);
    } else {
        printf("Number %d not found in the array.\n", target);
    }

    return 0;
}
