#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int info;
	struct node* link;
};
struct node* start = NULL;
void createList()
{
	if (start == NULL) {
		int n;
		printf("\nEnter the number of nodes: ");
		scanf("%d", &n);
		if (n != 0) {
			int data;
			struct node* newnode;
			struct node* temp;
			newnode = malloc(sizeof(struct node));
			start = newnode;
			temp = start;
			printf("\nEnter number to"
				" be inserted : ");
			scanf("%d", &data);
			start->info = data;

			for (int i = 2; i <= n; i++) {
				newnode = malloc(sizeof(struct node));
				temp->link = newnode;
				printf("\nEnter number to"
					" be inserted : ");
				scanf("%d", &data);
				newnode->info = data;
				temp = temp->link;
			}
		}
		printf("\nThe list is created\n");
	}
	else
		printf("\nThe list is already created\n");
}
void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));
	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);
	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}

void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		printf("\nEnter index : ");
		scanf("%d", &pos);
		position = malloc(sizeof(struct node));
		temp = start;
		while (i < pos - 1) {
			temp = temp->link;
			i++;
		}
		position = temp->link;
		temp->link = position->link;
		free(position);
	}
}
void count()
{

    struct node* temp = start;
 
 
    int count=0;
 
    while(temp != NULL){
 
       temp = temp->link;
 
        count++;
        
    }
    printf("%d is the number of nodes",count);
}

void traverse()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");

	else {
		temp = start;
		while (temp != NULL) {
			printf("Data = %d\n", temp->info);
			temp = temp->link;
		}
	}
}

int main()
{
	int choice;
	while (1) {


		printf("\t1 For insertion at any position\n");
		printf("\t2 For deletion of element at any position\n");
        printf("\t3 to Count\n");
		printf("\t4 To traverse the linked list\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
        insertAtPosition();
			break;
		case 2:
        deletePosition();
        	break;
		case 3:
			count();
			break;
		case 4:
			traverse();
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}