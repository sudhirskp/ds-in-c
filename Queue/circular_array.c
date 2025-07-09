#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (front == (rear+1)%MAX){
        printf("Queue is full.\n");
        return;
    }
    else if (front == -1 && rear == -1) {
         front = rear =0;
    }
    else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = data;
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
        printf("Deleted element is %d\n",queue[front]);
        front++;
    }

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    enqueue(77);
    enqueue(99);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(6);
    display();
    return 0;
}
