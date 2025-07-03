#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_data(struct node *head);

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

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 99;
    temp->next = NULL;
    head->next->next = temp;
    printf("list element :- ");
    print_data(head);
    
    return 0;
}

void print_data(struct node *head) {
    int count = 0;
    if (head == NULL) {
        printf("linked list is empty");
    } else {
        struct node *ptr = NULL;
        ptr = head;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
