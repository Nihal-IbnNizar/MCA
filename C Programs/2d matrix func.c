#include <stdio.h>

// Function to add two matrices
void addMatrices(int rows, int cols, int matrix1[][cols], int matrix2[][cols], int result[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int rows, int cols, int matrix1[][cols], int matrix2[][cols], int result[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int rows1, int cols1, int matrix1[][cols1], int rows2, int cols2, int matrix2[][cols2], int result[][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &rows1);

    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &cols1);

    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &rows2);

    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. The number of columns in matrix 1 must be equal to the number of rows in matrix 2.\n");
        return 1;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    // Input for the first matrix
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input for the second matrix
    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Matrix Addition
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(rows1, cols1, matrix1, matrix2, result);
        printf("The sum of the matrices is:\n");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Matrix addition is not possible. The matrices must have the same dimensions.\n");
    }

    // Matrix Subtraction
    if (rows1 == rows2 && cols1 == cols2) {
        subtractMatrices(rows1, cols1, matrix1, matrix2, result);
        printf("The difference of the matrices is:\n");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Matrix subtraction is not possible. The matrices must have the same dimensions.\n");
    }

    // Matrix Multiplication
    multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
    printf("The product of the matrices is:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

