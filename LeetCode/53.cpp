/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 53
 * Problem Title: Maximum Subarray
 * Keyword: dp
 *
 */

/* May also use divide and conquer, O(nlogn) */

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = nums[0];
        int max_sum = nums[0];
        for (int i = 1;i < nums.size();i++) {
            last = last < 0 ? nums[i] : last + nums[i];
            max_sum = max(max_sum, last);
        }
        return max_sum;
    }
};
