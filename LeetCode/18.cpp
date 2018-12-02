/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 18
 * Problem Title: 4Sum
 * Keyword: sort
 *
 */

#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nums_size = nums.size();
        if(nums_size < 4) return {};

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int fidx = 0;
        while(fidx < nums_size - 3) {
            int sidx = fidx + 1;
            while(sidx < nums_size - 2) {
                int tidx = sidx + 1,
                    foidx = nums_size - 1;
                int curr_val = target - (nums[fidx] + nums[sidx]);
                if(curr_val >= nums[tidx] + nums[tidx+1] && curr_val <= nums[foidx] + nums[foidx-1]) {
                    while(tidx < foidx) {
                        if(nums[tidx] + nums[foidx] < curr_val) {
                            tidx++;
                        }
                        else if(nums[tidx] + nums[foidx] > curr_val) {
                            foidx--;
                        }
                        else {
                            res.push_back({nums[fidx], nums[sidx], nums[tidx], nums[foidx]});
                            while(tidx + 1 < nums_size && nums[tidx] == nums[tidx+1]) tidx++;
                            tidx++;
                            while(foidx - 1 >= 0 && nums[foidx] == nums[foidx-1]) foidx--;
                            foidx--;
                        }
                    }
                }
                while(sidx + 1 < nums_size && nums[sidx] == nums[sidx+1]) sidx++;
                sidx++;
            }
            while(fidx + 1 < nums_size && nums[fidx] == nums[fidx+1]) fidx++;
            fidx++;
        }
        
        return res;
    }
};
