#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
};

void printList(struct node *head)
{
	struct node *temp = head;
	while(temp!=NULL){
		printf("\n%d",temp->data);
		temp = temp->next;
	}
}

void main()
{
	struct node newNode;
	newNode.data = 7;
	newNode.next = NULL;
	
	printf("%d",newNode.data);
	
	struct node newNode2;
	newNode2.data = 17;
	newNode2.next = NULL;
	
	newNode.next = &newNode2;
	
	struct node newNode3;
	newNode3.data = 37;
	newNode3.next = NULL;
	
	newNode2.next = &newNode3;
	
	struct node *temp = &newNode;
	while(temp!=NULL){
		printf("\n%d",temp->data);
		temp = temp->next;
	}
	#linked list from beginning
	int num;
	struct node *head = NULL;
	printf("\nhow many nodes do you need");
	scanf("%d",&num);
	int i;
	for(i =1;i<=num;i++){
		struct node *temp = malloc(sizeof(struct node));	
		
		int value;
		printf("\n Enter value of node");
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
	
	
	
	printList(head);
	
	#linked list at end
	
	struct node *head2 = NULL;
	printf("\nhow many nodes do you need");
	scanf("%d",&num);

	for(i =1;i<=num;i++){
		struct node *newData = malloc(sizeof(struct node));	
		
		int value;
		printf("\n Enter value of node");
		scanf("%d",&value);	
		
		newData->data = value;
		newData->next = NULL;
		
		if(head2==NULL)
		{ 			
			head2 = newData;
		}
		else{
			temp = head2;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newData;			
		}
		
	}
		printList(head2);
	
	
}
