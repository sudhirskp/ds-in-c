//Output Restricted Deque (ORDQ)
/*
Dequeue Front Only
Enqueue Front
Enqueue Rear
*/
#include <iostream>
using namespace std;

#define SIZE 10


class OutputRestrictedDeque {

    int arr[SIZE];
    int front, rear;

public:

    OutputRestrictedDeque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    // Insert at rear
    void enqueueRear(int x) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at rear.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear < SIZE - 1) {
            rear++;
        } else {
            cout << "No space at rear.\n";
            return;
        }

        arr[rear] = x;
        cout << "Inserted " << x << " at rear.\n";
    }

    // Insert at front
    void enqueueFront(int x) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at front.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front > 0) {
            front--;
        } else {
            cout << "No space at front.\n";
            return;
        }

        arr[front] = x;
        cout << "Inserted " << x << " at front.\n";
    }

    // Only front deletion allowed
    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow! Cannot delete.\n";
            return;
        }

        cout << "Deleted from front: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque: ";
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
	
    OutputRestrictedDeque dq;

    dq.enqueueRear(10);
    dq.enqueueRear(20);
    dq.enqueueFront(5);
    dq.enqueueFront(2);
    dq.display();

    dq.dequeue();  
    dq.display();

    dq.dequeue();
    dq.dequeue();
    dq.dequeue();
    dq.dequeue();  

    return 0;
}