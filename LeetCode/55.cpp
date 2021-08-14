/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 55
 * Problem Title: Jump Game
 * Keyword: 
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr_ub = 0,
            next_ub = 0;

        for (int curr_pos = 0;curr_pos < nums.size();curr_pos++) {
            if (curr_pos > curr_ub) {
                if (next_ub <= curr_ub) return false;
                curr_ub = next_ub;
            }

            int temp_pos = curr_pos + nums[curr_pos];
            if (temp_pos > next_ub) {
                next_ub = temp_pos;
            }
            if (next_ub >= nums.size() - 1) return true;
        }
    }
};
