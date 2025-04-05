#include <iostream>
using namespace std;

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    StackNode* top;
    

public:
    int count;
    Stack() {
        top = nullptr;
        count=0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        return false;
    }

    void push(int data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
        count++;

        cout<< "value pushed: " << data << endl;
        cout<< "count: " << count << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1; 
        }
        StackNode* temp = top;
        int poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
        count--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
        return top->data;
        
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        StackNode* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    cout << "Popped element: " << stack.pop() << endl;

    stack.display();

    return 0;
}