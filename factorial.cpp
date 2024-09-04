#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0)
        return 1;  // Base case: 0! = 1
    return n * factorial(n - 1);  // Recursive case
}

int main() {
    int n;
    
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %d\n", n, factorial(n));
    }

    return 0;
}
