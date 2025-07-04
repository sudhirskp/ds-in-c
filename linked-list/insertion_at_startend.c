#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
};
struct node *head = NULL;
void printList()
{
	struct node *temp = head;
	while(temp!=NULL){
		printf("\n%d",temp->data);
		temp = temp->next;
	}
}

void in_beg()
{
	struct node *temp = malloc(sizeof(struct node));	
		
		int value;
		printf("\n Enter value of node for beg node");
		scanf("%d",&value);	
		
		temp->data = value;
		if(head==NULL)
		{ 
			temp->next = NULL;
			head = temp;
		}
		else{
			temp->next = head;
			head = temp;
		}
}
void in_end()
{
	struct node *temp = malloc(sizeof(struct node));	
	struct node *newData = malloc(sizeof(struct node));	
		int value;
		printf("\n Enter value of node for end node");
		scanf("%d",&value);	
		
		newData->data = value;
		newData->next = NULL;
		if(head==NULL)
		{ 
			head = newData;
		}
		else{
			temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newData;
		}
}
void main()
{
	
	in_beg();
		printList();
		in_beg();
		printList();
		in_end();
		printList();
}