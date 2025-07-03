#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void data_end(struct node *head, int data);
void add(struct node* head, int data, int pos);
int main()
{
struct node *head = malloc(sizeof(struct node));
head->data = 45;
head->link = NULL;
printf("%d ", head->data);
data_end(head, 98);
data_end(head, 3);
int data = 67, position = 3;
add(head, data, position);
struct node *ptr = head;
while(ptr != NULL)
{
printf("%d", ptr->data);
ptr = ptr->link;
}
return 0;
}
void data_end(struct node *head, int data) {
    struct node *ptr, *end;
    end = malloc(sizeof(struct node));
    end->data = data;
    end->link = NULL;

    ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = end;
    printf("%d ", end->data);
}
void add(struct node* head, int data, int pos)
{
struct node *ptr = head;
struct node *ptr2 = malloc(sizeof(struct node));
ptr2->data = data;
ptr2->link = NULL;
pos-- ;
while (pos != 1)
{
ptr = ptr->link;
pos-- ;
}
ptr2->link = ptr->link;
ptr->link = ptr2;
}