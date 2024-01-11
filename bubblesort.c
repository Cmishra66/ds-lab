#include <stdio.h>
void bsort(int a[],int size)
{
    int i,j,temp=0;
    for(i=0;i<size;i++)
    {
        for(j=j+1;j<size;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }

            }
            printf("the sorted elements \n");
            for(i=0;i<size;i++)
            {
                printf("%d",a[i]);
            
            }
}
int main(void)
{
    int a[100];
    int i,j,temp;int size;
    printf("enter size of array\n");
    scanf("%d",&size);
    printf("enter elements of array");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    bsort(a[5],size);
return 0;
}
