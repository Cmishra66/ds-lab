/*
2.1 
WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array 

*/
#include <stdio.h>

void insert(int arr[],int size)
{
    int element,i;
    printf("Enter the Element : ");
    scanf("%d",&element);
    int position;
    printf("Enter Position : ");
    scanf("%d",&position);
    for(i=size;i>=position;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[position-1]=element;
    for(i=0;i<=size;i++)
    {
        printf("%d ",arr[i]);
    }
}

void delete(int arr[],int size)
{
    int position,i;
    printf("Enter Position to Delete: ");
    scanf("%d",&position);
    for(i=position-1;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    for(i=0;i<size-1;i++)
    {
        printf("%d ",arr[i]);
    }
}

void search(int arr[],int size)
{
    int element,i,c=0;
    printf("Enter the element you want to search : ");
    scanf("%d",&element);
    for(i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            c=1;
            printf("%d is Found on position %d.",element,i+1);
            break;
        }
    }
    if(c==0) printf("%d is not Found.",element);
}

void traversal(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int size;
    printf("Enter the Size of Array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d Array elements : ",size);
    int i;
    for(i=0;i<size;i++)
    {
        arr[i]=rand()%100;//scanf("%d",&arr[i]);
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    printf("*MENU*\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Search\n");
    printf("4.Traversal\n");
    int input;
    scanf("%d",&input);
    switch(input)
    {
        case 1:
        insert(arr,size);
        break;
        case 2:
        delete(arr,size);
        break;
        case 3:
        search(arr,size);
        break;
        case 4:
        traversal(arr,size);
        break;
        default:
        printf("Wrong Choice !!!");
    }
    return 0;
}