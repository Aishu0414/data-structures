#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            low = mid + 1;

        // If target is smaller, ignore the right half
        else
            high = mid - 1;
    }

    // Target is not present in the array
    return -1;
}

int main() {
    int n, target, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Perform binary search
    result = binarySearch(arr, 0, n - 1, target);

    // Output the result
    if (result != -1) {
        printf("Number %d found at index %d.\n", target, result);
    } else {
        printf("Number %d not found in the array.\n", target);
    }

    return 0;
}
