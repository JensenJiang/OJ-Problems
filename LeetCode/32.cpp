/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 32
 * Problem Title: Longest Valid Parentheses
 * Keyword: stack
 *
 */

/* another solution: also push the invalid parentheses info into the stack, and finally only invalid ones leave. then the range between these invalid indexes should be valid */

#include <string>
#include <stack>
#include <vector>
using std::string;
using std::stack;
using std::vector;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        vector<int> d(s.length(), 0);
        stack<int> st;
        for(int i = 0;i < s.length();i++) {
            if(s[i] == '(') st.push(i);
            else if(!st.empty()) {
                int li = st.top();
                st.pop();
                d[i] = li - i;
                d[li] = i - li + 1;
            }
        }
        int max_len = 0;
        for(int i = d.size() - 1;i >= 0;i--) {
            if(d[i] < 0 && i + 1 < d.size() && d[i+1] > 0) d[i + d[i]] += d[i+1];
            if(d[i] > 0 && max_len < d[i]) max_len = d[i];
        }
        return max_len;
    }
};
