#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head=NULL;
void create_list(int n)
{
    struct node *newnode, *ptr;
    int i;
    for(i=1;i<=n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
            printf("\n Overflow");
        else
        {
            printf("Enter info of newnode");
            scanf("%d", &newnode->info);
            newnode->next=NULL;
            if(head==NULL)
            {
                head=newnode;
                ptr=newnode;
            }
            else
            {
                ptr->next=newnode;
                ptr=newnode;
            }
            ptr->next=head;

        }
    }
}
void traverse_list()
{
    struct node *ptr=head->next;
    printf("\n The list is : ");
    while(ptr->next!=head->next)
    {
        printf("%d ->",ptr->info);
        ptr=ptr->next;
    }
    printf("%d",ptr->info);
}
void main()
{
    int n;
    printf("Enter no. of nodes to create:\n");
    scanf("%d",&n);
    create_list(n);
    traverse_list();
}