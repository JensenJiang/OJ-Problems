/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 98
 * Problem Title: Validate Binary Search Tree
 * Keyword: tree, bst
 *
 */

#include <limits>
#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::min()

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root, INT_MIN, INT_MAX);
    }
private:
    bool dfs(TreeNode *curr_node, long long l, long long r) {
        if(curr_node->val < l || curr_node->val > r) return false;
        if(curr_node->left && !dfs(curr_node->left, l, (long long)curr_node->val - 1)) return false;
        if(curr_node->right && !dfs(curr_node->right, (long long)curr_node->val + 1, r)) return false;
        return true;
    }
};
