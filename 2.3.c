#include <stdio.h>

void representSparseMatrix(int matrix[][100], int rows, int cols) {
    // Counting the number of non-zero elements in the matrix
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // Creating a 2D array to hold the triplet representation
    int triplet[nonZeroCount][3];
    int currentRow = 0;

    // Storing the triplet representation
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[currentRow][0] = i;
                triplet[currentRow][1] = j;
                triplet[currentRow][2] = matrix[i][j];
                currentRow++;
            }
        }
    }

    // Displaying the triplet representation
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

int main() {
    int rows, cols;
    
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Given Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Triplet Representation:\n");
    representSparseMatrix(matrix, rows, cols);

    return 0;
}