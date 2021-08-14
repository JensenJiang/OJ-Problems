/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 46
 * Problem Title: Permutations
 * Keyword: backtracking, good
 *
 */

/* Based on swap, see https://leetcode.com/problems/permutations/discuss/18247/My-elegant-recursive-C%2B%2B-solution-with-inline-explanation */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        cands = nums;
        // sort(cands.begin(), cands.end());
        dfs(0);
        return res;
    }
private:
    vector<int> cands;
    vector<vector<int>> res;
    void dfs(int curr_len) {
        for (int i = curr_len;i < cands.size();i++) {
            swap(cands[curr_len], cands[i]);
            if (curr_len + 1 < cands.size()) {
                dfs(curr_len + 1);
            }
            else {
                res.push_back(cands);
            }
            swap(cands[curr_len], cands[i]);
        }
    }
};
