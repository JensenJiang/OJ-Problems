/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 20
 * Problem Title: Valid Parentheses
 * Keyword: stack
 *
 */

#include <string>
#include <stack>
using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        bool valid = true;
        for(auto i = s.begin();i != s.end();i++) {
            if(*i == '(' || *i == '[' || *i == '{') char_stack.push(*i);
            else {
                if(char_stack.empty()) {
                    valid = false;
                    break;
                }
                char curr = char_stack.top();
                char_stack.pop();
                if(*i - curr != 1 && *i - curr != 2) {
                    valid = false;
                    break;
                }
            }
        }

        valid = valid && char_stack.empty();
        return valid;
    }
};
