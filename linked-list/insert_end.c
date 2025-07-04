#include<stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void data_end(struct node *head,int data);

int main() {
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 9;
    head->next = NULL;

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 18;
    temp->next = NULL;
    head->next = temp;
    printf("%d ", head->data);
    printf("%d ", temp->data);
    data_end(head,78);
    return 0;
}
    void data_end(struct node *head, int data) {
    struct node *ptr, *end;
    end = malloc(sizeof(struct node));
    end->data = data;
    end->next = NULL;

    ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = end;
    printf("%d", end->data);
}
