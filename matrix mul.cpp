#include <stdio.h>
#define MAX 10
void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Enter elements of the matrix (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int row1, col1, row2, col2;
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d%d", &row1, &col1);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d%d", &row2, &col2);
    if (col1 != row2) {
        printf("Matrix multiplication not possible.\n");
        return -1;
    }
    inputMatrix(matrix1, row1, col1);
    inputMatrix(matrix2, row2, col2);
    multiplyMatrices(matrix1, matrix2, result, row1, col1, col2);
    printf("Resultant Matrix:\n");
    displayMatrix(result, row1, col2);
    return 0;
}
