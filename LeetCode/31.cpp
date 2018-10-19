/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 31
 * Problem Title: Next Permutation
 * Keyword: google, permutation
 *
 */

#include <vector>
using std::vector;
using std::swap;
using std::reverse;
using std::upper_bound;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nr_nums = nums.size();
        if(nr_nums == 0 || nr_nums == 1) return;
        int end_ptr;
        for(end_ptr = nr_nums - 1;end_ptr > 0 && nums[end_ptr] <= nums[end_ptr-1];end_ptr--);

        reverse(nums.begin() + end_ptr, nums.end());
        if(end_ptr == 0) return;
        
        auto sub_ptr = upper_bound(nums.begin() + end_ptr, nums.end(), nums[end_ptr-1]);
        swap(*sub_ptr, nums[end_ptr-1]);
    }
};
