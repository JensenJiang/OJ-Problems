/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 35
 * Problem Title: Search Insert Position
 * Keyword: binary_search
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) r = mid;
            else l = r = mid;
        }
        return target <= nums[l] ? l : l + 1;
    }
};
