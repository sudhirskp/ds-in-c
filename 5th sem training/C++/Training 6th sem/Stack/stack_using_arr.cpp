#include<iostream>
using namespace std;

class Stack{
    int* arr;
    int top;
    int size;
    public:
    Stack(int size) : size(size) {
        arr = new int[size];
        top = -1;
    }


    public:
    void push(int data){
        if(isFull()){
            cout<< "Stack is full" << endl;
            return;
        }
        arr[++top] = data;
    }

    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == size - 1;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value
        }
        return arr[top--];
    }

    int capacity() {
        return top + 1;
    }

    void reverseStack() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        int temp = capacity();
        int* tempArr = new int[temp];
        int tempTop = 0;

        while (!isEmpty()) {
            tempArr[tempTop++] = pop();
        }

        for (int i = 0; i < temp; i++) {
            push(tempArr[i]);
        }

        delete[] tempArr;
    }


    int Search(int val){
        while(!isEmpty()){
            if(arr[top] == val){
                cout << "Value is Present " << arr[top] << endl;
                return arr[top];
            }
            pop();
        }
        
        cout << "Value is not Present" << endl;
        return -1;
    }

};

int main(){
    Stack s(5);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    // while(!s.isEmpty()){
    //     cout<< s.pop() << " ";
        
    // }

    s.Search(4);


    // cout<<"after reverse"<<endl;
    // s.reverseStack();
    // cout<< s.capacity() <<endl;
    // while(!s.isEmpty()){
    //     cout<< s.pop() << " ";
        
    // }
    // cout<< endl;
   

    return 0;
}