/*1.2 Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of
all the prime elements of the array using function and de-allocate the memory of the array after its use.*/


#include <stdio.h>
#include <stdlib.h>
int Prime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i*i <= n; ++i)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main() 
{
    int num;
    printf("Enter size of the array: ");
    scanf("%d", &num);
    int *arr = (int *)malloc(num * sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < num; ++i)
    {
        if (Prime(arr[i]))
        {
            sum += arr[i];
        }
    }
    printf("Sum = %d\n", sum);
    free(arr);
    return 0;
}