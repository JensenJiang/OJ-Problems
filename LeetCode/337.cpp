/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 337
 * Problem Title: House Robber III
 * Keyword: dp, tree, good
 *
 */

#include <algorithm>
#include <utility>
using std::pair;
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

typedef pair<int, int> ng_pair;

ng_pair get_max_sum(TreeNode *cur) {
    if(cur == nullptr) return {0, 0};
    ng_pair l_pair = get_max_sum(cur->left),
            r_pair = get_max_sum(cur->right);
    int not_steal = l_pair.second + r_pair.second;
    int global = max(not_steal, l_pair.first + r_pair.first + cur->val);
    return {not_steal, global};
}

class Solution {
public:
    int rob(TreeNode* root) {
        return get_max_sum(root).second;
    }
};
