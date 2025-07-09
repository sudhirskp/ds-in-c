#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* queue, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if (queue->front == NULL) {
        queue->front = temp;
    }
    else {
        queue->rear->next = temp;
    }
    queue->rear = temp;
    queue->rear->next = queue->front;
}

void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    else if (queue->front == queue->rear) {
        free(queue->front);
        queue->front = queue->rear = NULL;
    }
    else {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
        free(temp);
    }
}

void display(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Elements in the queue are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}

int main() {
    struct Queue queue = { NULL, NULL };
    enqueue(&queue,5);
    enqueue(&queue, 6);
    enqueue(&queue, 8);
    enqueue(&queue, 3);
    enqueue(&queue, 99);
    display(&queue);
    dequeue(&queue);
    dequeue(&queue);
    display(&queue);
    enqueue(&queue,7);
    display(&queue);
    return 0;
}
