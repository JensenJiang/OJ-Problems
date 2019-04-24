/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 456
 * Problem Title: 132 Pattern
 * Keyword: number-pattern, good, hard, monotone-queue
 *
 */

#include <vector>
#include <stack>
using std::vector;
using std::min;
using std::max;
using std::stack;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;

        int i = nums.size() - 2;
        stack<int> st;
        st.push(nums.back());
        for(;i >= 0 && nums[i] <= nums[i+1];i--) st.push(nums[i]);
        if(i < 0) return false;

        int max_2;
        while(!st.empty() && nums[i] > st.top()) {
            max_2 = st.top();
            st.pop();
        }
        st.push(nums[i]);
        i--;
        for(;i >= 0;i--) {
            if(nums[i] < max_2) return true;
            else if(nums[i] > max_2) {
                int last = nums[i];
                while(!st.empty() && nums[i] > st.top()) {
                    last = st.top();
                    st.pop();
                }
                if(nums[i] > last) {
                    max_2 = last;
                }
                st.push(nums[i]);
            }
        }    
        return false;
    }
};
