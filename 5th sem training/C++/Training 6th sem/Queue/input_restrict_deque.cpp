// Input Restricted Deque (IRDQ)
/*
Enqueue Rear Only
Dequeue Front
Dequeue Rear
*/
#include <iostream>
using namespace std;

#define SIZE 10

class InputRestrictedDeque {
    
	int arr[SIZE];
    int front, rear;

public:
    
	InputRestrictedDeque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Only rear insertion allowed
    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow! Cannot insert " << x << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        cout << "Inserted " << x << " at rear.\n";
    }

    // Deletion from front
    void dequeueFront() {
        if (isEmpty()) {
            cout << "Underflow! Cannot delete from front.\n";
            return;
        }

        cout << "Deleted from front: " << arr[front] << endl;
        front++;
    }

    // Deletion from rear
    void dequeueRear() {
        if (isEmpty()) {
            cout << "Underflow! Cannot delete from rear.\n";
            return;
        }

        cout << "Deleted from rear: " << arr[rear] << endl;
        rear--;
        if (rear < front) front = -1; // reset if empty
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
    
	InputRestrictedDeque dq;

    dq.enqueue(10);
    dq.enqueue(20);
    dq.enqueue(30);
    dq.display();

    dq.dequeueFront();
    dq.display();

    dq.dequeueRear();
    dq.display();

    dq.dequeueFront();
    dq.display();

    dq.dequeueFront();  

    return 0;

}