/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 40
 * Problem Title: Combination Sum II
 * Keyword: backtracking, dp, good
 *
 */

/* This is the DP solution */

#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        prev_nums.resize(target + 1);
        sort(candidates.begin(), candidates.end());
        for (int cand : candidates) {
            nr_cands[cand]++;
        }

        for (int curr_num : candidates) {
            for (int i = target - curr_num;i >= 0;i--) {
                if (prev_nums[i].size() > 0 || i == 0) {
                    prev_nums[i + curr_num].insert(curr_num);
                }
            }
        }
        vector<int> list;
        build_res(target, candidates.back(), list);
        return res;
    }
private:
    vector<unordered_set<int>> prev_nums;
    vector<vector<int>> res;
    unordered_map<int, int> nr_cands;
    void build_res(int target, int ub, vector<int>& curr_list) {
        curr_list.push_back(-1);
        for (int num : prev_nums[target]) {
            if (num <= ub && nr_cands[num] > 0) {
                curr_list.back() = num;
                nr_cands[num]--;
                if (target == num) {
                    res.push_back(curr_list);
                }
                else {
                    build_res(target - num, num, curr_list);
                }
                nr_cands[num]++;
            }
        }
        curr_list.pop_back();
    }
};
