/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 42
 * Problem Title: Trapping Rain Water
 * Keyword: good, monotone_queue
 *
 */

#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> st;
        for(int i = 0;i < height.size();i++) {
            int fill = 0,
                last_idx = -1;
            while(!st.empty() && height[st.top()] < height[i]) {
                int curr_idx = st.top();
                st.pop();
                if(!st.empty()) {
                    int next_idx = st.top();
                    fill += (curr_idx - next_idx) * height[curr_idx];
                }
                last_idx = curr_idx;
            }
            if(!st.empty()) {
                res = res + (i - st.top() - 1) * height[i] - fill;
            }
            else if(last_idx >= 0) {
                res = res + (i - last_idx - 1) * height[last_idx] - fill;
            }
            st.push(i);
        }
        return res;
    }
};
