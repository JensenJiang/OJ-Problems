/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 17
 * Problem Title: Letter Combinations of a Phone Number
 * Keyword: corner_case, string
 *
 */

#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using std::vector;
using std::string;
using std::queue;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        queue<string> q;
        q.push("");

        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            int curr_len = curr.length();
            int curr_digit = digits[curr_len] - '0';
            int nr_letters = strlen(a[curr_digit]);
            for(int i = 0;i < nr_letters;i++) {
                string new_str = curr + a[curr_digit][i];

                if(curr_len == digits.length() - 1) {
                    res.push_back(new_str);
                }
                else {
                    q.push(new_str);
                }
            }
        }

        return res;
    }
private:
    static const char* a[];
};

const char* Solution::a[] = {nullptr, nullptr, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("");
    for(auto i = res.begin();i != res.end();i++) {
        printf("%s\n", i->c_str());
    }
}
