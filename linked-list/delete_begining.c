#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
struct node* del_first(struct node *head);
int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = 77;
    newNode->next = NULL;
    head->next = newNode;
    struct node *newNode2 = malloc(sizeof(struct node));
    newNode2->data = 9;
    newNode2->next = NULL;
    newNode->next = newNode2;
    struct node *ptr=NULL;
    ptr=head;
    printf("Before:");
    while(ptr!=NULL){
     printf(" %d ", ptr->data);
     ptr=ptr->next;
    }
    head=del_first(head);
    struct node *ptr1;
    ptr1=head;
    printf("\nAfter:");
    while(ptr1!=NULL){
     printf("%d ", ptr1->data);
     ptr1=ptr1->next;
    }
    return 0;
}
struct node* del_first(struct node *head)
{
if(head == NULL)
printf("List is already empty!");
else
{
struct node *temp = head;
head = head->next;
free (temp);
}
return head;
}
