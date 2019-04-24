/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 27
 * Problem Title: Remove Element
 * Keyword: in_place
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unsigned int new_ptr = 0;
        for(int curr_val : nums) {
            if(curr_val != val) nums[new_ptr++] = curr_val;
        }
        return new_ptr;
    }
};
