/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 394
 * Problem Title: Decode String
 * Keyword: string, google
 *
 */

#include <string>
#include <stack>
#include <cstdio>
using std::string;
using std::stack;

struct stack_data {
    string *curr_s;
    int k;
};

class Solution {
public:
    string decodeString(string s) {
        int curr_i = 0;
        stack<stack_data> st;
        st.push({nullptr, 0});
        string *ret_s = nullptr;
        
        while(!st.empty() || curr_i < s.length()){
            stack_data curr_d = st.top();
            st.pop();
            string *curr_s = curr_d.curr_s;
            if(!curr_s) {
                curr_s = new string("");
            }
            else {
                for(int i = 0;i < curr_d.k;i++) curr_s->append(*ret_s);
            }
            // printf("%s\n", curr_s->c_str());
            for(;curr_i < s.length() && is_en_letter(s[curr_i]);curr_i++) curr_s->append(1, s[curr_i]);
            if(curr_i < s.length()) {
                if(s[curr_i] == ']') {
                    ret_s = curr_s;
                }
                else {
                    int si = curr_i;
                    for(;s[curr_i] != '[';curr_i++);
                    int new_k = stoi(s.substr(si, curr_i - si));
                    // printf("%d\n", new_k);
                    st.push({curr_s, new_k});
                    st.push({nullptr, 0});
                }
                curr_i++;
            }
            else {
                ret_s = curr_s;
            }
        }
        return *ret_s;
    }
private:
    bool is_en_letter(const char a) {
        return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
    }
};

int main() {
    Solution s;
    printf("%s\n", s.decodeString(string("3[a]2[bc]")).c_str());
}
