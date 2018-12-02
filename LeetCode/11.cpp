/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 11
 * Problem Title: Container With Most Water
 * Keyword: good, hard
 *
 */

#include <vector>
#include <limits>
#define INT_MIN std::numeric_limits<int>::min()
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = INT_MIN;
        int i = 0,
            j = height.size() - 1;
        while(i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j]) {
                int curr_val = height[i],
                    curr_idx = i + 1;
                while(curr_idx < j && height[curr_idx] <= curr_val) curr_idx++;
                i = curr_idx;
            }
            else {
                int curr_val = height[j],
                    curr_idx = j - 1;
                while(curr_idx > i && height[curr_idx] <= curr_val) curr_idx--;
                j = curr_idx;
            }
        }
        return res;
    }
};
