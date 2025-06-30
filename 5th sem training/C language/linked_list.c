#include <stdio.h>
#include <stdlib.h>

int main() {
    struct node {
        int data;
        struct node *next;
    };

    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    // Add 2nd node in the linked list
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = 20;
    second->next = NULL;
    head->next = second;

    struct node *count;
    count = head;
    while (count != NULL) {
        printf("%d ", count->data);
        count = count->next;
        
    }

    return 0;
}
