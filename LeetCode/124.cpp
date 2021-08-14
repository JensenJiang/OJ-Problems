/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 124
 * Problem Title: Binary Tree Maximum Path Sum
 * Keyword: google, dp
 *
 */

#include <limits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSingleDirPath(root);
        return max_path_len;
    }
private:
    int max_path_len = std::numeric_limits<int>::min();
    int maxSingleDirPath(TreeNode* curr) {
        if (curr == nullptr) return 0;

        int max_lpath_len,
            max_rpath_len;
        max_lpath_len = std::max(maxSingleDirPath(curr->left), 0);
        max_rpath_len = std::max(maxSingleDirPath(curr->right), 0);
        
        max_path_len = std::max(curr->val + max_lpath_len + max_rpath_len, max_path_len);
        return curr->val + std::max(max_lpath_len, max_rpath_len);
    }
};
