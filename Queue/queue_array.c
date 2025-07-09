//Here is a sample implementation of a queue using an array in C:

#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("queue is full\n");
        exit(1);
    } 
    else {
        if (front == -1) {
            front =0;
        }
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1) {
        printf("empty queue\n");
        return;
    } 
    else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void print() {
    if (front == -1) {
        printf("queue is empty\n");
        return;
    }
     else {
        printf("The elements in the queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(4);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    print();
    dequeue();
    print();
    return 0;
}