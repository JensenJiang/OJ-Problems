/*
* Author: Jensen Jiang<jensenjiang1995@gmail.com>
* Problem ID: 103
* Problem Title:  Binary Tree Zigzag Level Order Traversal
* Keyword: microsoft, tree
*
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> next_nodes;
        if (root) next_nodes.push_back(root);

        for (int curr_depth = 0;!next_nodes.empty();curr_depth++) {
            vector<int> level_ans;
            int curr_size = next_nodes.size();
            if (curr_depth % 2 == 0) {
                for (int i = 0;i < curr_size;i++) {
                    TreeNode *curr_node = next_nodes.front();
                    next_nodes.pop_front();
                    level_ans.push_back(curr_node->val);
                    if (curr_node->left) next_nodes.push_back(curr_node->left);
                    if (curr_node->right) next_nodes.push_back(curr_node->right);
                }
            }
            else {
                for (int i = 0;i < curr_size;i++) {
                    TreeNode *curr_node = next_nodes.back();
                    next_nodes.pop_back();
                    level_ans.push_back(curr_node->val);
                    if (curr_node->right) next_nodes.push_front(curr_node->right);
                    if (curr_node->left) next_nodes.push_front(curr_node->left);
                }
            }
            
            ans.emplace_back(move(level_ans));
        }
        
        return ans;
    }
};
