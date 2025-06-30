#include<stdio.h>
#include<stdlib.h>
int main(){
    struct node {
        int data;
        struct node *link;
    };
    struct node *k;
    k = (struct node *)malloc(sizeof(struct node));
    k->data = 10;
    k->link = k;

    printf("%d %u",k->data,k->link);
   
}