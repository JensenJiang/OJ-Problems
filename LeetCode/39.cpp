/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 39
 * Problem Title: Combination Sum
 * Keyword: backtracking
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cands = candidates;
        sort(cands.begin(), cands.end());
        vector<int> list;
        dfs(0, target, list);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> cands;

    void dfs(int start_idx, int target, vector<int>& curr_list) {
        curr_list.push_back(-1);
        int curr_len = curr_list.size();
        for (int i = start_idx;i < cands.size();i++) {
            if (cands[i] < target) {
                curr_list[curr_len-1] = cands[i];
                dfs(i, target - cands[i], curr_list);
            }
            else if (cands[i] == target) {
                curr_list[curr_len-1] = cands[i];
                res.emplace_back(curr_list);
                break;
            }
            else {
                break;
            }
        }
        curr_list.pop_back();
    }
};
