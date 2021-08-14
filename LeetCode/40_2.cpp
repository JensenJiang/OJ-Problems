/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 40
 * Problem Title: Combination Sum II
 * Keyword: backtracking, good
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        cands.push_back(candidates[0]);
        nr_cands.push_back(1);
        for (int i = 1;i < candidates.size();i++) {
            if (candidates[i] == candidates[i - 1]) {
                nr_cands.back()++;
            }
            else {
                cands.push_back(candidates[i]);
                nr_cands.push_back(1);
            }
        }
        vector<int> list;
        dfs(0, target, list);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> cands;
    vector<int> nr_cands;

    void dfs(int start_idx, int target, vector<int>& curr_list) {
        for (int i = start_idx;i < cands.size();i++) {
            int tot = 0;
            for (int j = 1;j <= nr_cands[i];j++) {
                tot += cands[i];
                if (tot < target) {
                    curr_list.push_back(cands[i]);
                    dfs(i + 1, target - tot, curr_list);
                }
                else if (tot == target) {
                    curr_list.push_back(cands[i]);
                    res.emplace_back(curr_list);
                    break;
                }
                else {
                    break;
                }
            }
            while (!curr_list.empty() && curr_list.back() == cands[i]) curr_list.pop_back();
        }
    }
};
