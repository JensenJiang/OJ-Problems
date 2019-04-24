/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 416
 * Problem Title: Partition Equal Subset Sum
 * Keyword: dp, knapsack
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int e : nums) sum += e;
        if(sum % 2 != 0) return false;

        sum /= 2;
        bool *vis = new bool[sum + 1];
        for(int i = 0;i <= sum;i++) vis[i] = false;
        vis[0] = true;
        for(int e : nums) {
            if(e > sum) return false;
            for(int i = sum;i > 0;i--) {
                if(!vis[i] && i >= e && vis[i-e]) vis[i] = true;
            }
            if(vis[sum]) return true;
        }
        return vis[sum];
    }
};
