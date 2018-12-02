/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 15
 * Problem Title: 3Sum
 * Keyword: good, sort
 *
 */

#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int fidx = 0;
        while(fidx < nums.size() - 2) {
            int sidx = fidx + 1,
                tidx = nums.size() - 1,
                curr_val = -nums[fidx];
            if(curr_val < 0) break;
            while(sidx < tidx) {
                if(nums[sidx] + nums[tidx] < curr_val) {
                    sidx++;
                }
                else if(nums[sidx] + nums[tidx] > curr_val) {
                    tidx--;
                }
                else {
                    res.push_back({nums[fidx], nums[sidx], nums[tidx]});
                    while(sidx + 1 < nums.size() && nums[sidx] == nums[sidx+1]) sidx++;
                    sidx++;
                    while(tidx - 1 >= 0 && nums[tidx] == nums[tidx-1]) tidx--;
                    tidx--;
                }
            }
            while(fidx + 1 < nums.size() && nums[fidx] == nums[fidx+1]) fidx++;
            fidx++;
        }
        return res;
    }
};
