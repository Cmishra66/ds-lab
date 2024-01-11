#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Employee {
    int employeeNo;
    char employeeName[50];
    int salary;
    struct Employee *next;
    struct Employee *prev;
} Employee;

void insert(Employee **head, int employeeNo, char *employeeName, int salary) {
    Employee *new_employee = (Employee *)malloc(sizeof(Employee));
    new_employee->employeeNo = employeeNo;
    strcpy(new_employee->employeeName, employeeName);
    new_employee->salary = salary;
    new_employee->next = NULL;
    new_employee->prev = NULL;

    if (*head == NULL) {
        *head = new_employee;
        return;
    }

    Employee *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_employee;
    new_employee->prev = temp;
}

void delete(Employee **head, int employeeNo) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Employee *temp = *head;
    while (temp != NULL) {
        if (temp->employeeNo == employeeNo) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Employee deleted successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Employee not found.\n");
}


void display(Employee *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Employee *temp = head;
    printf("List of employees:\n");
    while (temp != NULL) {
        printf("Employee No: %d\n", temp->employeeNo);
        printf("Employee Name: %s\n", temp->employeeName);
        printf("Salary: %d\n", temp->salary);
        temp = temp->next;
    }
}

int main() {
    Employee *head = NULL;
    int choice, employeeNo;
    char employeeName[50];
    int salary;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee number: ");
                scanf("%d", &employeeNo);
                printf("Enter employee name: ");
                scanf("%s", employeeName);
                printf("Enter salary: ");
                scanf("%d", &salary);
                insert(&head, employeeNo, employeeName, salary);
                break;
            case 2:
                printf("Enter employee number to delete: ");
                scanf("%d", &employeeNo);
                delete(&head, employeeNo);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}