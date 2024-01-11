#include<stdio.h>
int main()
{
    int s ,ar[100],i,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);

    printf("enter your elements\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&ar[i]);
    }
    printf("Enter the number to be searched\n");
    scanf("%d",&s);
    for(i=0;i<=n;i++)
    {
        if(ar[i]==s)
        {
        printf("The element found in position %d",i+1);
        break;
        }
    }
    if(i==n)
    
    printf("No element found");
    
    return 0;
    
}
