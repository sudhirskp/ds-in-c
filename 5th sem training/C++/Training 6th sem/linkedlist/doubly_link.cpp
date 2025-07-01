#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class linkedList {
public:
    Node* head;

    linkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void insertAthead(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int ele) {
        insert(ele); // same as insert
    }

    void push_front(int ele) {
        insertAthead(ele); // same as insertAthead
    }

    void addAtSepecificPosition(int pos, int ele) {
        if (pos == 0) {
            insertAthead(ele);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(ele);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteHead() {
        if (head == nullptr) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* tail = head->prev;
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }

    void DeleteAtSepecific(int pos) {
        if (head == nullptr) return;
        if (pos == 0) {
            deleteHead();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos && temp->next != head; i++) {
            temp = temp->next;
        }

        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        if (temp == head) head = nextNode;
        delete temp;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    linkedList ll;

    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50);
    ll.display();

    ll.push_front(100);
    ll.display();

    ll.push_front(200);
    ll.push_front(300);
    ll.display();

    ll.push_back(1000);
    ll.push_back(2000);
    ll.display();

    ll.insertAthead(10000);
    ll.display();

    ll.addAtSepecificPosition(2, 500);
    ll.display();

    ll.DeleteAtSepecific(3);
    ll.display();

    ll.deleteHead();
    ll.display();

    return 0;
}
