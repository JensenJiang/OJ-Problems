/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 410
 * Problem Title: Split Array Largest Sum
 * Keyword: good, hard, binary_search
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int max_v = nums[0];
        int nums_sum = 0;
        for(int e : nums) {
            if(e > max_v) max_v = e;
            nums_sum += e;
        }
        
        if(nums.size() == m) return max_v;
        if(m == 1) return nums_sum;
        int l = max_v, r = nums_sum;
        while(l < r) {
            int mid = (l + r) / 2;
            int idx = 0,
                curr_sum = 0,
                re_sum = nums_sum;
            for(int split = m - 1;split > 0;split--) {
                while(split <= nums.size() - idx - 1 && curr_sum + nums[idx] <= mid) {
                    curr_sum += nums[idx];
                    idx++;
                }
                re_sum -= curr_sum;
                curr_sum = 0;
            }
            if(re_sum <= mid) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
