#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct node
{
    int data;
    struct node *next;
    struct node *head;
    
};
void main ()
{
  struct node *head=NULL;
  
    struct node *node1;
    node1->data =6;
    node1->next =head;
    
    struct node *node2;
  
      node2->data =8;
      node1->next =node2;
      node2->next =NULL;
    
//insert newnode
      struct node *newnode;
      newnode=malloc(sizeof(struct node));
      newnode->data =4;
      newnode->next =node1;
      head=newnode;
      
}