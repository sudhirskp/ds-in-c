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
        height = 1;
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










    Node* rightRotate(Node* X) {
        Node* Y = X->left;
        Node* T = Y->right;

        // Perform rotation
        Y->right = X;
        X->left = T;

        // Update heights
        X->height = 1 + max(getHeight(X->left), getHeight(X->right));
        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right));

        return Y;
    }



    Node* leftRotate(Node* X) {
        Node* Y = X->right;
        Node* T = Y->left;

        // Perform rotation
        Y->left = X;
        X->right = T;

        // Update heights
        X->height = 1 + max(getHeight(X->left), getHeight(X->right));
        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right));

        return Y;
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



		// Starting AVL Implementation...


        // 2. Update height of this ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        
        // 3. Get balance factor
        int balance = getBalance(node);






		//[ we need, 'balance' and 'key' ]





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
    
    ~AVLTree() {
        delete root;
    }

};


//DRIVER CODE
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