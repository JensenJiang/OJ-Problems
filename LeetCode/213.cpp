/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 213
 * Problem Title: House Robber II
 * Keyword: dp
 *
 */

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size_nums = nums.size();
        if(size_nums == 0) return 0;
        else if(size_nums == 1) return nums[0];
        else if(size_nums == 2) return max(nums[0], nums[1]);

        vector<int> global(size_nums, 0), local(size_nums, 0);
        
        /* When house 0 is stolen */
        local[0] = nums[0];
        global[0] = local[0];
        local[1] = 0;
        global[1] = local[0];
        
        for(int i = 2;i < size_nums;i++) {
            local[i] = global[i - 2] + nums[i];
            global[i] = max(global[i - 1], local[i]);
        }
        int max_1 = global[size_nums - 2];

        /* When house 1 is not stolen */
        local[0] = 0;
        global[0] = 0;
        local[1] = nums[1];
        global[1] = local[1];
        
        for(int i = 2;i < size_nums;i++) {
            local[i] = global[i - 2] + nums[i];
            global[i] = max(global[i - 1], local[i]);
        }
        int max_2 = global[size_nums - 1];
        return max(max_1, max_2);
    }
};
