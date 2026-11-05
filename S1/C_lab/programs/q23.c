#include <stdio.h>

// Function declarations - notice we use 'rows' and 'cols' to dynamically set bounds
void readMatrix(int rows, int cols, int matrix[rows][cols], char name);
void multiplyMatrices(int r1, int c1, int c2, int first[r1][c1], int second[c1][c2], int result[r1][c2]);
void displayMatrix(int rows, int cols, int matrix[rows][cols], char* name);

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("\nError: Multiplication not possible! Columns of A must match rows of B.\n");
        return 0; 
    }

    // Declaring arrays using the exact variables entered by the user
    int first[r1][c1];
    int second[r2][c2];
    int result[r1][c2];

    printf("\n--- Input Matrix A ---\n");
    readMatrix(r1, c1, first, 'A');

    printf("\n--- Input Matrix B ---\n");
    readMatrix(r2, c2, second, 'B');

    multiplyMatrices(r1, c1, c2, first, second, result);

    printf("\n--- Results ---\n");
    displayMatrix(r1, c1, first, "Matrix A");
    displayMatrix(r2, c2, second, "Matrix B");
    displayMatrix(r1, c2, result, "Product Matrix (A x B)");

    return 0;
}

// i) Read matrix elements
void readMatrix(int rows, int cols, int matrix[rows][cols], char name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element %c[%d][%d]: ", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// ii) Multiply matrices
void multiplyMatrices(int r1, int c1, int c2, int first[r1][c1], int second[c1][c2], int result[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

// iii) Display matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols], char* name) {
    printf("%s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

