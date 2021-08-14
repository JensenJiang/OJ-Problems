/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 47
 * Problem Title: Permutations II
 * Keyword: backtracking, good
 *
 */

/* Based on swap */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};
        totlen = nums.size();
        sort(nums.begin(), nums.end());
        cands.push_back({nums.front(), 1});
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] == nums[i - 1]) {
                cands.back().second++;
            }
            else {
                cands.push_back({nums[i], 1});
            }
        }
        dfs(0);
        return res;
    }
private:
    int totlen;
    vector<pair<int, int>> cands;
    vector<int> partial_res;
    vector<vector<int>> res;

    void dfs(int begin) {
        partial_res.push_back(0);

        for (int i = begin;i < cands.size();i++) {
            swap(cands[begin], cands[i]);
            partial_res.back() = cands[begin].first;
            cands[begin].second--;

            if (partial_res.size() < totlen) {
                dfs(cands[begin].second > 0 ? begin : begin + 1);
            }
            else {
                res.push_back(partial_res);
            }

            cands[begin].second++;
            swap(cands[begin], cands[i]);
        }

        partial_res.pop_back();
    }
};
