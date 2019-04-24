struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        tot = 0;
        dfs(root, true);
        return tot;
    }
private:
    int dfs(TreeNode *curr_node, bool is_root) {
        if(curr_node == nullptr) return 1;
        int l_val = dfs(curr_node->left, false);
        int r_val = dfs(curr_node->right, false);
        if(l_val == 0 || r_val == 0 || (l_val == 1 && r_val == 1 && is_root)) {
            tot++;
            return 2;
        }
        else if(l_val == 2 || r_val == 2) return 1;
        else return 0;
    }
    int tot;
};
