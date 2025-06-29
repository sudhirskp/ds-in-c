#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
       
    }
};

class BinaryTree {
    public:
    Node * CreateTree();
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
};

Node* BinaryTree::CreateTree() {

    int val;
    cout << "Enter data (-1 or no node) ";
    cin >> val;
    if (val == -1) {
        return nullptr;
    }
    Node *newNode = new Node(val);
    cout << "Enter left child of " << val << endl;
    newNode->left = CreateTree(); // Recursive call to create left subtree
    cout << "Enter right child of " << val << endl;
    newNode->right = CreateTree(); // Recursive call to create right subtree
    return newNode;
}

void BinaryTree::inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void BinaryTree::postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
   
}

void BinaryTree::preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    BinaryTree tree;
    Node* root = tree.CreateTree();
    cout << "Inorder Traversal: ";
    tree.inorder(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    tree.preorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    tree.postorder(root);
    cout << endl;
    return 0;
}