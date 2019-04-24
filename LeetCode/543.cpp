/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 543
 * Problem Title: Diameter of Binary Tree
 * Keyword: tree, dp
 *
 */

#include <algorithm>
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        longest_to_leaf(root);
        return ans;
    }
private:
    int ans = 0;
    int longest_to_leaf(TreeNode* curr) {
        if(curr->left == nullptr && curr->right == nullptr) return 0;
        int ll = curr->left ? longest_to_leaf(curr->left) + 1 : 0;
        int rl = curr->right ? longest_to_leaf(curr->right) + 1 : 0;
        if(ans < ll + rl) ans = ll + rl;
        return max(ll, rl);
    }
};
