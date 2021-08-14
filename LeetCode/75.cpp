/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 75
 * Problem Title: Sort Colors
 * Keyword: sort, microsoft
 *
 */

#include <vector>
#include <algorithm>
using std::vector;
using std::swap;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        long ptr[3]{0, 0, long(nums.size() - 1)};

        while (ptr[1] <= ptr[2]) {
            switch(nums[ptr[1]]) {
                case 0:
                    swap(nums[ptr[0]], nums[ptr[1]]);
                    ptr[0]++;
                    ptr[1]++;
                    break;
                case 2:
                    swap(nums[ptr[2]], nums[ptr[1]]);
                    ptr[2]--;
                    break;
                default:
                    ptr[1]++;
                    break;
            }
        }
    }
};
