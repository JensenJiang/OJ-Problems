/* Subtree with Maximum Average
 * https://www.lintcode.com/problem/subtree-with-maximum-average/description
 * Amazon OA2 2019
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        max_avg = -numeric_limits<double>::infinity();
        if(root == nullptr) return nullptr;
        count_subtree_size(root);
        return max_tree;
    }
private:
    double max_avg;
    TreeNode *max_tree;
    pair<int, int> count_subtree_size(TreeNode *curr) {
        int curr_size = 1,
            curr_sum = curr->val;
        if(curr->left) {
            auto lpair = count_subtree_size(curr->left);
            curr_size += lpair.first;
            curr_sum += lpair.second;
        }
        if(curr->right) {
            auto rpair = count_subtree_size(curr->right);
            curr_size += rpair.first;
            curr_sum += rpair.second;
        }
        double curr_avg = double(curr_sum) / curr_size;
        if(curr_avg > max_avg) {
            max_avg = curr_avg;
            max_tree = curr;
        }
        return {curr_size, curr_sum};
    }
};
