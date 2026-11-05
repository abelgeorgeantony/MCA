#include <stdio.h>

// Function declaration for transposing only
void transposeMatrix(int rows, int cols, int original[rows][cols], int transpose[cols][rows]);

int main() {
    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int original[rows][cols];
    int transpose[cols][rows];

    // Read the matrix elements
    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &original[i][j]);
        }
    }

    // Perform only the transposing using the function
    transposeMatrix(rows, cols, original, transpose);

    // Display the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", original[i][j]);
        }
        printf("\n");
    }

    // Display the transposed matrix (notice loop runs up to cols then rows)
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function that handles ONLY the transposing math
void transposeMatrix(int rows, int cols, int original[rows][cols], int transpose[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = original[i][j];
        }
    }
}

