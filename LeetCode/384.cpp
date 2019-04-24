/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 384
 * Problem Title: Shuffle an Array
 * Keyword: random, good, hard
 *
 */

#include <vector>
#include <cstdlib>
using std::vector;
using std::swap;

class Solution {
public:
    Solution(vector<int> nums) {
        vec_nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = vec_nums;
        for(int i = vec_nums.size() - 1;i > 0;i--) {
            int j = rand() % (i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }
private:
    vector<int> vec_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
