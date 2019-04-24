/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 334 
 * Problem Title: Increasing Triplet Subsequence
 * Keyword: number-pattern, good, monotone-queue
 *
 */

#include <vector>
#include <stack>
using std::vector;
using std::stack;
using std::numeric_limits;
#define INT_MAX numeric_limits<int>::max();

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int curr_min = INT_MAX;
        stack<int> st;
        for(int e : nums) {
            if(e > curr_min) return true;
            else {
                if(e < curr_min) {
                    while(!st.empty() && e <= st.top()) {
                        st.pop();
                    }

                    if(!st.empty()) {
                        curr_min = e;
                    }
                    else st.push(e);
                }
            }
        }
        return false;
    }
};
