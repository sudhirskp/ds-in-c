#include <iostream>
using namespace std;

class Node {
public: 
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedList {
public:
    Node* head;

    linkedList() {
        head = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAthead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }


    void push_back(int ele){
        Node* newNode = new Node(ele);

        newNode->data = ele;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void push_front(int ele){
        Node* newNode = new Node(ele);
        newNode->next = head;
        head = newNode;
    }


    void addAtSepecificPosition(int pos, int ele){
        Node* newNode = new Node(ele);
        Node* temp = head;
        for(int i = 0; i < pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteHead(){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    void DeleteAtSepecific(int pos){
        Node* temp = head;
        if(pos == 0){
            head = head->next;
            delete temp;
            return;
        }
        for(int i = 0; i < pos - 1; i++){
            temp = temp->next;
        }
        Node* nodeforDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeforDelete;
    }


    void display() { 
       
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl; 
    }


};

int main() {
    linkedList ll;
    // ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50);
    //ll.display();
    // ll.push_back(10);
    // ll.push_back(20);
    // ll.push_back(30);
    // ll.push_back(50);

    // ll.push_front(10);
    // ll.push_front(20);
    // ll.push_front(30);
    // ll.push_front(40);

    // ll.insertAthead(10);
    // ll.insertAthead(20);
    // ll.insertAthead(30);

    ll.addAtSepecificPosition(2, 100);
    ll.display();
    //ll.deleteHead();
    ll.display();
    ll.DeleteAtSepecific(2);
    ll.display();

}