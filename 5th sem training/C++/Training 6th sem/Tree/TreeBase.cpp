#include<iostream>
using namespace std;
#include<queue>


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
    void bfs(Node*);
    void levelorder(Node*);
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

//algo-
//1.add root element in the queue
//2.perform the below step untill the queue is empty
//3.pop the front element from the queue and print it or store then print
//4.if the popped element has left child then add it to the queue
//5.if the popped element has right child then add it to the queue


void BinaryTree::bfs(Node* root){
    // if(root == nullptr) {
    //     return;
    // }
    // queue<Node*> q;
    // q.push(root);
    // while(!q.empty()) {
    //     Node* current = q.front();
    //     q.pop();
    //     cout << current->data << " ";
    //     if(current->left != nullptr) {
    //         q.push(current->left);
    //     }
    //     if(current->right != nullptr) {
    //         q.push(current->right);
    //     }
    // }

    int front = -1 , rear = -1;
    Node* queue[100]; 
    if(root == nullptr) return ;
    queue[++rear] = root;
    while(front != rear) {
        Node* current = queue[++front]; 
        cout << current->data << " ";
        
       
        if(current->left != nullptr) {
            queue[++rear] = current->left;
        }
        
        if(current->right != nullptr) {
            queue[++rear] = current->right;
        }
    }
}

TreeNode* BST::insert(TreeNode* root, int val){
	if(root == NULL)
	   return new TreeNode(val);
	else if(val < root->data)
	   root->left = insert(root->left, val);
	else
	   root->right = insert(root->right, val); 
}


void BinaryTree::levelorder(Node* root){
    if(root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if(current->left != nullptr) {
                q.push(current->left);
            }
            if(current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
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