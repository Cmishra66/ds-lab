#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int findLargest(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int findSmallest(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int height(struct Node* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1; // Node is a leaf
    } else {
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nMain Menu\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Display Largest Element\n");
        printf("7. Display Smallest Element\n");
        printf("8. Height of the Tree\n");
        printf("9. Count Leaf Nodes\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Element %d found in the tree.\n", value);
                } else {
                    printf("Element %d not found in the tree.\n", value);
                }
                break;
            case 6:
                if (root != NULL) {
                    printf("Largest Element: %d\n", findLargest(root));
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 7:
                if (root != NULL) {
                    printf("Smallest Element: %d\n", findSmallest(root));
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 8:
                printf("Height of the Tree: %d\n", height(root));
                break;
            case 9:
                printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
                break;
            case 10:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 10);

    return 0;
}