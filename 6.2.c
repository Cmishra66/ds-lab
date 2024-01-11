
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *top=NULL;
void push(int n){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Stack Overflow\n");
    }
    else{
        newnode->info=n;
        newnode->next=top;
        top=newnode;
    }
}
void pop(){
    struct node *ptr;
    if(top==NULL){
        printf("Stack Underflow\n");
    }
    else{
        ptr=top;
        top=top->next;
        printf("Popped element is %d\n",ptr->info);
        free(ptr);
    }
}
void display(){
    struct node *ptr;
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        ptr=top;
        printf("Stack elements are:\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->info);
            ptr=ptr->next;
        }
    }
}
void main(){
    int choice,n;
    while(1){
        printf("Enter your choice:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        while(1) {
            switch (choice) {
                case 1:
                    printf("Enter the element to be pushed:\n");
                    scanf("%d", &n);
                    push(n);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(0);
            }
        }
    }
}