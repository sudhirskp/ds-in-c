#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("queue is full\n");
        exit(1);
    } 
    else {
        newnode->data = data;
        newnode->next = NULL;
        if (rear == NULL) {
            front = newnode;
            rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }
}

void dequeue() {
    if (front == NULL) {
        printf("empty queue\n");
        return;
    }
    else {
        printf("Dequeue element is %d\n", front->data);
        front = front->next;
    }
}

void print() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("queue is empty\n");
        return;
    }
    else {
        printf("The Enqueue element in the queue are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(4);
    enqueue(23);
    enqueue(45);
    enqueue(1);
    print();
    dequeue();
    print();
    return 0;
}
