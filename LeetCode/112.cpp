/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 112
 * Problem Title: Path Sum
 * Keyword: tree
 *
 */

#include <stack>
using std::stack;
using std::pair;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        stack<pair<TreeNode*, int>> st;
        st.push({root, sum});
        while(!st.empty()) {
            TreeNode *curr_node = st.top().first;
            int curr_sum = st.top().second;
            st.pop();

            if(curr_node->left == nullptr && curr_node->right == nullptr) {
                if(curr_node->val == curr_sum) return true;
            }
            else {
                if(curr_node->left) st.push({curr_node->left, curr_sum - curr_node->val});
                if(curr_node->right) st.push({curr_node->right, curr_sum - curr_node->val});
            }
        }
        return false;
    }
};
