/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 34
 * Problem Title: Find First and Last Position of Element in Sorted Array
 * Keyword: binary_search, good
 *
 */

/* add a biased mid calculation when the search may stuck */

#include <vector>
using std::vector;

int findFirst(const vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(nums[mid] < target) l = mid + 1;
        else if(nums[mid] > target) r = mid;
        else {
            if(mid - 1 >= 0 && nums[mid - 1] == target) r = mid;
            else {
                l = mid;
                break;
            }
        }
    }
    if(l < nums.size() && nums[l] == target) return l;
    else return -1;
}

int findLast(const vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(nums[mid] < target) l = mid + 1;
        else if(nums[mid] > target) r = mid;
        else l = mid;
    }
    if(l < nums.size() && nums[l] == target) return l;
    else return -1;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};

