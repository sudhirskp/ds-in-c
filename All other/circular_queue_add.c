#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node {
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (front==NULL)    {
        front=rear=newnode;
    }
    else {
        rear->next =newnode;
        newnode->next = front;
        rear=newnode;
    }
}
void main() {
    
}
    