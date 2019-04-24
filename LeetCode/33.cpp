/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 33
 * Problem Title: Search in Rotated Sorted Array
 * Keyword: binary_search, good
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        else if(nums.size() == 1) return nums[0] == target ? 0 : -1;

        int d = 0;
        if(nums.front() > nums.back()) {
            int l = 1, r = nums.size() - 1;
            while(l < r) {
                int mid = (l + r) / 2;
                if(nums[mid] > nums[0]) l = mid + 1;
                else r = mid;
            }
            d = l;
        }

        int n = nums.size();
        int l = d, r = d + n - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid % n] < target) l = mid + 1;
            else if(nums[mid % n] > target) r = mid - 1;
            else l = r = mid;
        }
        return (l == r && nums[l % n] == target) ? l % n : -1;
    }
};
