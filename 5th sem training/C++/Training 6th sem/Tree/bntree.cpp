#include<iostream>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;

public:
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node* root = nullptr;

    void insertLeft(int data) {
        Node* newNode = new Node(data);
        if (!root) {
            root = newNode;
            return;
        }
        if (!root->left) {
            root->left = newNode;
        } else {
            cout << "Left child already exists!" << endl;
        }
    }

    void insertRight(int data) {
        Node* newNode = new Node(data);
        if (!root) {
            root = newNode;
            return;
        }
        if (!root->right) {
            root->right = newNode;
        } else {
            cout << "Right child already exists!" << endl;
        }
    }

    void display() {
        if (!root) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Root: " << root->data << endl;
        if (root->left) {
            cout << "Left Child: " << root->left->data << endl;
        } else {
            cout << "Left Child: NULL" << endl;
        }
        if (root->right) {
            cout << "Right Child: " << root->right->data << endl;
        } else {
            cout << "Right Child: NULL" << endl;
        }
    }
};

int main() {
    Node tree(10); 
    tree.insertLeft(5); 
    tree.insertRight(15); 
    tree.display(); 

    return 0;
}