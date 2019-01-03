/* Greedy algorithm(sliding window) or binary search ans */
/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 209
 * Problem Title: Minimum Size Subarray Sum
 * Keyword: binary_search, good, sliding_window
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 0,
            j = 0,
            n = nums.size(),
            curr_sum = nums[0];
        int min_len = n + 1;
        for(;i < n;) {
            for(;j + 1 < n && curr_sum < s;) {
                j++;
                curr_sum += nums[j];
            }
            if(curr_sum >= s) {
                if(min_len > j - i + 1) min_len = j - i + 1;
            }
            else if(j == n - 1) break;
            
            curr_sum -= nums[i];
            i++;
        }
        if(min_len < n + 1) return min_len;
        else return 0;
    }
};
