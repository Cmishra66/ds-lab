//1.1 Write a program to read two numbers and compare the numbers using function call by address.


#include<stdio.h>
void compare(int *n1,int *n2)
{
    if(*n1>*n2)
    printf("%d is bigger than %d",*n1,*n2);

    else if(*n2>*n1)
    printf("%d is bigger than %d",*n2,*n1);

    else
    printf("%d is is equal to %d",*n1,*n2);
}
int main()
{
    int n1,n2;
    printf("Enter 2 Numbers : ");
    scanf("%d %d",&n1,&n2);
    compare(&n1,&n2);
    return 0;
}