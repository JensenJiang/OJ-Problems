/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 687
 * Problem Title: Longest Univalue Path
 * Keyword: google, tree, dp
 *
 */

#include <queue>
using std::queue;
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct bfs_info {
    TreeNode *node;
    int par_val;
    int par_max;
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        max_l = 0;
        dfs(root);
        return max_l;
    }

private:
    int max_l;
    int dfs(TreeNode *curr) {
        int lmax = 0, rmax = 0;
        if(curr->left) {
            lmax = dfs(curr->left);
            if(curr->val == curr->left->val) lmax++;
            else lmax = 0;
        }
        if(curr->right) {
            rmax = dfs(curr->right);
            if(curr->val == curr->right->val) rmax++;
            else rmax = 0;
        }
        
        max_l = max(lmax + rmax, max_l);
        return max(lmax, rmax);
    }
};
