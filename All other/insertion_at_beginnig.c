#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Set the data in the new node
    newNode->data = newData;

    // Update the new node's next pointer to point to the current head
    newNode->next = *headRef;

    // Update the head of the list to point to the new node
    *headRef = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    return 0;
}
