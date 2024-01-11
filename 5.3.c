
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int col, value;
    struct Node* next;
} Node;

typedef struct SparseMatrix {
    int rows, cols;
    Node** header;
} SparseMatrix;

SparseMatrix* createSparseMatrix(int rows, int cols) {
    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;

    matrix->header = (Node*)malloc(rows * sizeof(Node));
    for (int i = 0; i < rows; i++) {
        matrix->header[i] = (Node*)malloc(sizeof(Node));
        matrix->header[i]->next = NULL;
    }

    return matrix;
}

void insert(SparseMatrix* matrix, int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;

    Node* current = matrix->header[row];
    while (current->next != NULL && current->next->col < col) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void display(SparseMatrix* matrix) {
    printf("Sparse Matrix representation using header single linked list:\n");
    for (int i = 0; i < matrix->rows; i++) {
        Node* current = matrix->header[i]->next;

        printf("Row %d: ", i);
        while (current != NULL) {
            printf("(Col: %d, Value: %d) ", current->col, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;


    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);


    SparseMatrix* matrix = createSparseMatrix(rows, cols);

    int numNonZero = 0;

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            scanf("%d", &value);
            if (value != 0) {
                numNonZero++;
                insert(matrix, i, j, value);
            }
        }
    }


    display(matrix);

    return 0;
}
