/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 38
 * Problem Title: Count and Say
 * Keyword:
 *
 */

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string countAndSay(int n) {
        for(int i = ans.size();i < n;i++) {
            string& last = ans[i-1];
            string curr;
            for(int j = 0;j < last.length();) {
                int k;
                for(k = j;k < last.length() - 1 && last[k] == last[k+1];k++);
                curr += ('0' + k - j + 1);
                curr += last[j];
                j = k + 1;
            }
            ans.push_back(curr);
        }
        return ans[n-1];
    }
private:
    static vector<string> ans;
};

vector<string> Solution::ans = {
            "1",
            "11",
            "21",
            "1211",
            "111221"
        };
