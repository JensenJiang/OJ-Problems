/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 110
 * Problem Title: Balanced Binary Tree
 * Keyword: tree, microsoft
 *
 */

#include <cstdlib>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        balanced = true;
        
        if (root) depth(root);

        return balanced;
    }
private:
    bool balanced;
    int depth(TreeNode *root) {
        int ldepth = root->left ? depth(root->left) : 0,
            rdepth = root->right ? depth(root->right) : 0;

        if (abs(ldepth - rdepth) > 1) balanced = false;

        return std::max(ldepth, rdepth) + 1;
    }
};
