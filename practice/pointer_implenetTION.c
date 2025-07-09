#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void del_end(struct node *head); // Add a semicolon here

void print(struct node *head);

int main() { // Changed void to int for main function
    struct node *head = NULL;
    head = malloc(sizeof(struct node));
    head->data = 4;
    head->next = NULL;

    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = 7;
    temp->next = NULL;
    head->next = temp;

    temp = malloc(sizeof(struct node));
    temp->data = 10;
    temp->next = NULL;
    head->next->next = temp;
    printf("before:\n");
    print(head);
    del_end(head);
    printf(" after:\n");
    print(head);

    return 0; // Added return statement
}

void print(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void del_end(struct node *head) {
    if (head == NULL) {
        printf("List is already empty!\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
