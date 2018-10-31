/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 10
 * Problem Title: Regular Expression Matching
 * Keyword: google, dp
 *
 */

#include <string>
#include <vector>
using std::string;
using std::vector;

struct pEle {
    char sym;
    bool is_star;
    bool match(const char a) {
        return a == sym || sym == '.' || (is_star && a == '\0');
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<pEle> v_p;
        for(int i = 0;i < p.length();i++) {
            bool is_star = false;
            char sym = p[i];
            if(i + 1 < p.length() && p[i+1] == '*') {
                is_star = true;
                i++;
            }
            v_p.push_back({sym, is_star});
        }

        bool **dp = new bool*[s.length()+1];
        for(int i = 0;i < s.length()+1;i++) dp[i] = new bool[v_p.size()];
        int e1 = s.length(), e2 = v_p.size();
        s.push_back('\0');
        v_p.push_back({'\0', false});
        dp[e1][e2] = v_p[e2].match(s[e1]);
        for(int j = e2 - 1;j >= 0;j--) dp[e1][j] = v_p[j].is_star && dp[e1][j+1];
        for(int i = e1 - 1;i >= 0;i--) {
            for(int j = e2;j >= 0;j--) {
                dp[i][j] = (i < e1 && v_p[j].is_star && dp[i+1][j] && v_p[j].match(s[i])) || \
                           (j < e2 && v_p[j].is_star && dp[i][j+1]) || \
                           (i < e1 && j < e2 && dp[i+1][j+1] && v_p[j].match(s[i]));
            }
        }

        return dp[0][0];
    }
};
