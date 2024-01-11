/*
1.3 Write a program to create a structure to store the information of n number of Employees. Employee’s
information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the
information of employees with gross salary. Use array of structure.
*/

#include<stdio.h>
struct employ
{
    int id;
    char name[30];
    char des[20];
    float salary;
    float hra;
    float da;
    float gross;
};
int main()
{
    printf("Enter the Number of Employee :");
    int n;
    scanf("%d",&n);
    struct employ emp[n];

    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter details for Employee #%d:\n", i + 1);
        printf("Employee_Id : ");
        scanf("%d", emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Designation: ");
        scanf("%s", emp[i].des);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].salary);
        printf("HRA Percentage: ");
        scanf("%f", &emp[i].hra);
        printf("DA Percentage: ");
        scanf("%f", &emp[i].da);
        emp[i].gross = emp[i].salary + (emp[i].hra / 100) * emp[i].salary + (emp[i].da / 100) * emp[i].salary;                       
    }

    printf("\nEmployee Information with Gross Salary:\n");
    printf("Emp-ID\tName\tDesignation\tBasic Salary\tHRA%%\tDA%%\tGross Salary\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n%s\n%s\n%.2f\n%.2f\n%.2f\n%.2n\n",emp[i].id,emp[i].name,emp[i].des,emp[i].salary,emp[i].hra,emp[i].da,emp[i].gross);
    }


    return 0;
}