#include <stdio.h>

// Function to find the number of nonzero elements in the matrix
int countNonZero(int mat[][10], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangular(int mat[][10], int n) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                printf("%d ", mat[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to display elements just above and below the main diagonal
void displayDiagonalNeighbors(int mat[][10], int n) {
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i - 1 || j == i + 1) {
                printf("%d ", mat[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[10][10];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Number of nonzero elements: %d\n", countNonZero(matrix, n));
    displayUpperTriangular(matrix, n);
    displayDiagonalNeighbors(matrix, n);

    return 0;
}