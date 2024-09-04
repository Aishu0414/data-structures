#include <stdio.h>

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int numbers[n];

    // Input the numbers
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Classify and display each number as odd or even
    printf("Odd numbers:\n");
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 != 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    printf("Even numbers:\n");
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    return 0;
}
