#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
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
            newnode->prev=NULL;
            if(head==NULL)
            {
                head=newnode;
                ptr=newnode;
            }
            else
            {
                ptr->next=newnode;
                newnode->prev=ptr;
                ptr=newnode;
            }

        }
    }
    tail=ptr;
}
void traverse_list()
{
    struct node *ptr=head;
    printf("\n The list is : ");
    while(ptr->next!=NULL)
    {
        printf("%d ->",ptr->info);
        ptr=ptr->next;
    }
    printf("%d",ptr->info);
}
void insert(int n){
    struct node *newnode, *ptr;
    int pos;
    printf("enter insertion position:\n");
    scanf("%d",&pos);
    printf("enter element to insert:\n");
    scanf("%d",&newnode->info);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(pos==1){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    else if(pos==n){
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
    else{
        ptr=head;
        int i;
        for(i=1;i<pos-1;i++){
            ptr=ptr->next;
        }
        newnode->next=ptr->next;
        newnode->prev=ptr;
        ptr->next=newnode;
        newnode->next->prev=newnode;
    }
}
void delete(int n){
    struct node *ptr,*temp;
    int pos;
    printf("Enter deletion position:\n");
    scanf("%d",&pos);
    if(pos==1){
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    else if(pos==n){
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
    }
    else{
        ptr=head;
        for(int i=1;i<pos-1;i++){
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=temp->next;
        temp->next->prev=ptr;
        free(temp);
    }
    printf("\nDeletion complete");
}
void main() {
    int n;
    printf("Enter number of nodes to create\n");
    scanf("%d", &n);
    create_list(n);
    printf("---Operation choice---\n1.Insert\n2.Delete\n3.Traverse\n4.exit\n");
    int choice;
    while (1) {
        printf("\nEnter choice:\n");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                insert(n);
                break;
            case 2:
                delete(n);
                break;
            case 3:
                traverse_list();
                break;
            case 4:
                exit(0);
        }
    }
}