#include <stdio.h>

// Function to calculate factorial using iteration
unsigned long long factorial(int n) {
    unsigned long long result = 1;  // Use unsigned long long to handle large results

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int n;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %llu\n", n, factorial(n));
    }

    return 0;
}
