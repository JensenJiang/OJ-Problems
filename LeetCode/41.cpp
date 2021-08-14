/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 41
 * Problem Title: First Missing Positive
 * Keyword: good
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0;i < nums.size();i++) {
            int curr = nums[i];
            nums[i] = -1;
            while (curr >= 1 && curr <= nums.size() && curr != nums[curr - 1]) swap(curr, nums[curr - 1]);
        }

        for (int i = 0;i < nums.size();i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        return nums.size() + 1;
    }
};
