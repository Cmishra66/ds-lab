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

// Function to display the list of employees
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

    // Insertion
    insert(&head, 1, "mukesh", 5000);
    insert(&head, 2, "ramesh", 6000);
    display(head);

    // Deletion
    delete(&head, 1);
    display(head);

    return 0;
}