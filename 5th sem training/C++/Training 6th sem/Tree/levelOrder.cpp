#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class bst {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> que;
        if (root == nullptr) return ans;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            std::vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                vec.push_back(node->val);
                que.pop();
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

int main(){
    // Example usage
    bst tree;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> result = tree.levelOrder(root);
    
    for(const auto& level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}