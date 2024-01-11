#include <stdio.h>
#include <stdlib.h>


struct SparseMatrix {
    int row;
    int col;
    int value;
};

int main() {
    int m, n, numElements1, numElements2;

    printf("Enter the number of rows and columns in the matrices: ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of non-zero elements in matrix 1: ");
    scanf("%d", &numElements1);

    printf("Enter the number of non-zero elements in matrix 2: ");
    scanf("%d", &numElements2);

   
    struct SparseMatrix *matrix1 = (struct SparseMatrix *)malloc(numElements1 * sizeof(struct SparseMatrix));
    struct SparseMatrix *matrix2 = (struct SparseMatrix *)malloc(numElements2 * sizeof(struct SparseMatrix));

    printf("Enter the elements of matrix 1 in 3-tuple format (row col value):\n");
    for (int i = 0; i < numElements1; i++) {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }

    printf("Enter the elements of matrix 2 in 3-tuple format (row col value):\n");
    for (int i = 0; i < numElements2; i++) {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }

    
    if (m != n || numElements1 != numElements2) {
        printf("Matrix dimensions are not compatible for addition.\n");
        free(matrix1);
        free(matrix2);
        return 1;
    }

    struct SparseMatrix *resultMatrix = (struct SparseMatrix *)malloc(numElements1 * sizeof(struct SparseMatrix));

    // Perform the addition of the two matrices
    int resultCount = 0;
    for (int i = 0; i < numElements1; i++) {
        resultMatrix[i].row = matrix1[i].row;
        resultMatrix[i].col = matrix1[i].col;
        resultMatrix[i].value = matrix1[i].value + matrix2[i].value;
        if (resultMatrix[i].value != 0) {
            resultCount++;
        }
    }

    // Print the result matrix in 3-tuple format
    printf("Result matrix in 3-tuple format:\n");
    printf("%d %d %d\n", m, n, resultCount);
    for (int i = 0; i < numElements1; i++) {
        if (resultMatrix[i].value != 0) {
            printf("%d %d %d\n", resultMatrix[i].row, resultMatrix[i].col, resultMatrix[i].value);
        }
    }

    // Free allocated memory
    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}
