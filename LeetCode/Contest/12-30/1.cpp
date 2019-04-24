struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <queue>
using std::queue;

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr_node = q.front();
            q.pop();
            if(curr_node->left) {
                if(curr_node->left->val != val) return false;
                q.push(curr_node->left);
            }
            if(curr_node->right) {
                if(curr_node->right->val != val) return false;
                q.push(curr_node->right);
            }
        }
        return true;
    }
};
