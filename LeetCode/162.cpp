/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 162
 * Problem Title: Find Peak Element
 * Keyword: google, binary_search
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int nums_size = nums.size();
        if(nums_size == 1) return 0;
        if(nums[0] >= nums[1]) return 0;
        if(nums[nums_size - 1] >= nums[nums_size - 2]) return nums_size - 1;
        int l = 1, r = nums_size - 1;
        while(l + 1 < r) {
            int m = (l + r) / 2;
            if(nums[m] >= nums[m - 1] && nums[m] >= nums[m + 1]) return m;
            else if(nums[m] >= nums[m - 1]) l = m + 1;
            else r = m;
        }
        return l;
    }
};
