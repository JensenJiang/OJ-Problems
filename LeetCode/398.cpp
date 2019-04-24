/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 398
 * Problem Title: Random Pick Index
 * Keyword: random, good
 *
 */

#include <vector>
#include <cstdlib>
using std::vector;

class Solution {
public:
    Solution(vector<int> nums) {
        vec_nums = nums;
    }
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for(int i = 0;i < vec_nums.size();i++) {
            if(vec_nums[i] == target) {
                cnt++;
                if(rand() % cnt == 0) res = i;
            }
        }
        return res;
    }
private:
    vector<int> vec_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
