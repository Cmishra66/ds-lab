/*

1.4 Write a menu driven program to create a structure to represent complex number and perform the
following operation using function :
1. addition of two complex number (call by value)
2. multiplication of two complex number (call by address)

*/

#include <stdio.h>
struct Complex
{
    float real;
    float imaginary;
};
void add(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    printf("Sum = %.2f + %.2fi\n", result.real, result.imaginary);
}
void multiply(struct Complex *c1, struct Complex *c2)
{
    struct Complex result;
    result.real = c1->real * c2->real - c1->imaginary * c2->imaginary;
    result.imaginary = c1->real * c2->imaginary + c1->imaginary * c2->real;
    printf("Product = %.2f + %.2fi\n", result.real, result.imaginary);
}
int main()
{
    struct Complex complex1, complex2;
    int choice;
    int end;
    printf("Enter complex number 1 (real imaginary): ");
    scanf("%f %f", &complex1.real, &complex1.imaginary);
    printf("Enter complex number 2 (real imaginary): ");
    scanf("%f %f", &complex2.real, &complex2.imaginary);
    do
    {
        printf("MENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add(complex1, complex2);
                break;
            case 2:
                multiply(&complex1, &complex2);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Enter 0 to Exit.\n");
        printf("Enter 1 to do Again.\n");
        scanf("%d",&end);
    } while (end != 0);
    printf("\nEND HERE !!!\n");
    return 0;
}