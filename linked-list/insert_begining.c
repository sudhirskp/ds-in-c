#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* add_beg(struct node* head);

int main() {
struct node *head = malloc(sizeof(struct node));
head->data = 77;
head->next = NULL;
struct node *ptr = malloc(sizeof(struct node));
ptr->data = 66;
ptr->next = NULL;
head->next = ptr;
int data;
head = add_beg(head);
ptr = head;
while(ptr != NULL)
{
printf("%d ", ptr->data);
ptr = ptr->next;
}
return 0;
}
struct node* add_beg(struct node* head)
{
struct node *ptr = malloc(sizeof(struct node));
ptr->data = 98;
//ptr->next = NULL;
ptr->next = head;
head = ptr;
return head;
}