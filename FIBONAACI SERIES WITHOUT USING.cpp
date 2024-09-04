#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci series up to %d terms:\n", n);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            next = first;
        } else if (i == 1) {
            next = second;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    printf("\n");

    return 0;
}
