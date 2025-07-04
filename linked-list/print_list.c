#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
void del_sep(struct node *head);
int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 11;
    head->next = NULL;
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = 13;
    newNode->next = NULL;
    head->next = newNode;
    struct node *newNode2 = malloc(sizeof(struct node));
    newNode2->data = 24;
    newNode2->next = NULL;
    newNode->next = newNode2;
    struct node *ptr=NULL;
    ptr=head;
    printf("list of nodes:");
    while(ptr!=NULL){
     printf(" %d ", ptr->data);
     ptr=ptr->next;
    }
}