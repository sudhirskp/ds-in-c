#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void count_of_nodes(struct node *head);

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
    temp->data = 90;
    temp->next = NULL;
    head->next->next = temp;

    printf("%d\n", temp->data);
    printf("%d\n", temp->data);
    printf("%d\n", head->data);

    count_of_nodes(head);
    return 0;
}

void count_of_nodes(struct node *head) {
    int count = 0;
    if (head == NULL) {
        printf("linked list is empty");
    } else {
        struct node *ptr = NULL;
        ptr = head;
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        printf("Number of nodes in the linked list: %d\n", count);
    }
}
