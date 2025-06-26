#include <iostream>
#include <algorithm>
using namespace std;

class Node {
	
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1; // Initially, a new node is a leaf (height 1)
    }
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insertNode(Node* node, int key) {
        // 1. Perform normal BST insertion
        if (node == nullptr)
            return new Node(key);
            
		//*** Simple BST Insertion
        if (key < node->data)
            node->left = insertNode(node->left, key);
        else if (key > node->data)
            node->right = insertNode(node->right, key);
        else
            return node; // Duplicates not allowed

        // 2. Update height of this ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3. Get balance factor
        int balance = getBalance(node);

        // 4. Balance the node if needed
        // Case 1 - Left Left
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // Case 2 - Right Right
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // Case 3 - Left Right
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Case 4 - Right Left
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // return unchanged
    }

    void inorderTraversal(Node* node) {
        if (!node) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void display() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    int getRootBalance() {
        return getBalance(root);
    }
};

int main() {
    AVLTree tree;
    int n, val;

    cout << "Total Nodes: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Node Value " << (i + 1) << ": ";
        cin >> val;
        tree.insert(val);
    }

    tree.display();

    return 0;
}
