/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 45
 * Problem Title: Jump Game II
 * Keyword: good, hard
 *
 */

/* Reference: https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy */

#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int curr_end = 0,
            next_end = 0,
            nr_jumps = 0;

        for (int i = 0;i < nums.size();i++) {
            if (i > curr_end) {
                nr_jumps++;
                curr_end = next_end;
            }
            next_end = max(next_end, i + nums[i]);
        }

        return nr_jumps;
    }
};
