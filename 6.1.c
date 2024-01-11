#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push(int n){
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=n;
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Popped element is %d\n",stack[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are:\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
void main(){
    int choice,n;
    while(1){
        printf("Enter your choice:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be pushed:\n");
                scanf("%d",&n);
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
            default:
                printf("Invalid choice\n");
        }
    }
}