#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


class BinarySearchTree {

private:

    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = nullptr;
        }
    };
    Node* root;


    Node* insert(Node* node, int value) {
     
	    if (!node)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            cout << "Duplicate values are not allowed.\n";

        return node;
    
	}



    bool search(Node* node, int key) {
        if (!node) return false;

        if (key == node->data) return true;
        if (key < node->data) return search(node->left, key);
        return search(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return nullptr;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            // Node found
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* successor = findMin(node->right);
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data);
            }
        }
        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void levelOrder(Node* node) {
        if (!node) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int height(Node* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int findMinValue(Node* node) {
        if (!node) return -1;
        Node* minNode = findMin(node);
        return minNode ? minNode->data : -1;
    }

    int findMaxValue(Node* node) {
        if (!node) return -1;
        while (node->right)
            node = node->right;
        return node->data;
    }
    
    void reverseInorder(Node* node) {
	    if (node) {
	        reverseInorder(node->right);
	        cout << node->data << " ";
	        reverseInorder(node->left);
	    }
	}


public:
	
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void searchValue(int key) {
        if (search(root, key))
            cout << key << " found.\n";
        else
            cout << key << " not found.\n";
    }

    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    void displayInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    void displayLevelOrder() {
        cout << "Level-order: ";
        levelOrder(root);
        cout << endl;
    }

    void showMinMax() {
        cout << "Min: " << findMinValue(root) << ", Max: " << findMaxValue(root) << endl;
    }

    void showHeight() {
        cout << "Height of tree: " << height(root) << endl;
    }

    void showNodeCount() {
        cout << "Total nodes: " << countNodes(root) << endl;
    }
    
    void displayAscending() {
	    cout << "Ascending Order: ";
	    inorder(root);
	    cout << endl;
	}
	
	void displayDescending() {
	    cout << "Descending Order: ";
	    reverseInorder(root);
	    cout << endl;
	}

};

int main() {
    BinarySearchTree bst;
    int choice, value;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Inorder\n5. Preorder\n6. Postorder\n";
        cout << "7. Level-order\n8. Min & Max\n9. Height\n10. Count Nodes\n";
        cout << "11. Sort Ascending\n12. Sort Descending\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bst.insert(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            bst.searchValue(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            bst.deleteValue(value);
            break;
        case 4:
            bst.displayInorder();
            break;
        case 5:
            bst.displayPreorder();
            break;
        case 6:
            bst.displayPostorder();
            break;
        case 7:
            bst.displayLevelOrder();
            break;
        case 8:
            bst.showMinMax();
            break;
        case 9:
            bst.showHeight();
            break;
        case 10:
            bst.showNodeCount();
            break;
        case 11:
		    bst.displayAscending();
		    break;
		case 12:
		    bst.displayDescending();
		    break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
