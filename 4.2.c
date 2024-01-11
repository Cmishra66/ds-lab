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
	if (start == NULL)
	 {
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
			printf("\nEnter number to be inserted : ");
			scanf("%d",&data);
			start->info = data;

			for (int i = 2; i <= n; i++) 
			{
				newnode = malloc(sizeof(struct node));
				temp->link = newnode;
				printf("\nEnter number to be inserted : ");
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
  struct node* temp=start;
  int count=0;
  while(temp!=NULL)
  {
    temp = temp->link;
	count++;

  }
  printf("The total number of node are %d\t",count);
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

void search()
{
    int found = -1;
    struct node* tr = start;
 
    if (start == NULL) {
        printf("Linked list is empty\n");
    }
    else {
        printf("\nEnter the element you want to search: ");
        int key;
        scanf("%d", &key);
        while (tr != NULL) 
		{
            if (tr->info == key) {
                found = 1;
                break;
            }

            else 
			{
                tr = tr->link;
            }
        }
        if (found == 1)
		{
            printf( "Yes, %d is present in the linked list.\n",key);
        }
        else {
            printf("No, %d is not present in the linked "
                   "list.\n",
                   key);
        }
    }
}
void sort()
{
    struct node* current = start;
    struct node* index = NULL;
    int temp;
 
    // If LL is empty
    if (start == NULL) {
        return;
    }
 
    // Else
    else {
 
        // Traverse the LL
        while (current != NULL) {
            index = current->link;
            while (index != NULL) {
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
 
            // Update the current
            current = current->link;
        }
    }
}
void reverseLL()
{
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;
    if (start == NULL)
        printf("List is empty\n");
    else {

        while (start != NULL) {
 
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
        temp = start;
 
        printf("Reversed linked list is : ");
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->link;
        }
    }
}
 
int main()
{
	int choice;
	while (1) 
	{
        printf("\t1 For insertion at any position\n");
		printf("\t2 For deletion of element at any position\n");
        printf("\t3 to Count\n");
		printf("\t4 to traverse the linked list\n");
		printf("\t5 Search an element in linked list\n");
		printf("\t6 Sort the linked list");
		printf("\t7To reverse the linked list\n");
		printf("\t8 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice)
		{
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
		case 5:
			search();
			break;
		case 6:
			sort();
			break;
	    case 7:
			reverseLL();
			break;
        case 8:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}