/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 16
 * Problem Title: 3Sum Closest
 * Keyword: good
 *
 */

#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>
#define INT_MAX std::numeric_limits<int>::max()
using std::vector;
using std::sort;
using std::abs;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // if(nums.size() < 3) return {};

        sort(nums.begin(), nums.end());
        int fidx = 0;
        int delta = INT_MAX;
        while(fidx < nums.size() - 2) {
            int sidx = fidx + 1,
                tidx = nums.size() - 1,
                curr_val = target - nums[fidx];
            while(sidx < tidx) {
                int curr_sum = nums[sidx] + nums[tidx];
                if(curr_sum < curr_val) {
                    if(abs(delta) > abs(curr_sum - curr_val)) delta = curr_sum - curr_val;
                    sidx++;
                }
                else if(curr_sum > curr_val) {
                    if(abs(delta) > abs(curr_sum - curr_val)) delta = curr_sum - curr_val;
                    tidx--;
                }
                else {
                    return target;
                    // while(sidx + 1 < nums.size() && nums[sidx] == nums[sidx+1]) sidx++;
                    // sidx++;
                    // while(tidx - 1 >= 0 && nums[tidx] == nums[tidx-1]) tidx--;
                    // tidx--;
                }
            }
            while(fidx + 1 < nums.size() && nums[fidx] == nums[fidx+1]) fidx++;
            fidx++;
        }
        return target + delta;
    }
};
