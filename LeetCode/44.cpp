/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 44
 * Problem Title: Wildcard Matching
 * Keyword: dp, string
 *
 */

/* Some optimization here: https://leetcode.com/problems/wildcard-matching/discuss/17810/Linear-runtime-and-constant-space-solution, but the time complexity is still O(mn). */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1));

        /* Init dp array */
        dp[0][0] = true;
        for (int i = 1;i <= s.length();i++) {
            dp[i][0] = false;
        }
        bool only_star = true;
        for (int i = 1;i <= p.length();i++) {
            only_star = only_star && (p[i - 1] == '*');
            dp[0][i] = only_star;
        }

        for (int i = 1;i <= s.length();i++) {
            for (int j = 1;j <= p.length();j++) {
                dp[i][j] = (dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?' || p[j - 1] == '*')) || (dp[i][j - 1] && p[j - 1] == '*') || (dp[i - 1][j] && p[j - 1] == '*');
            }
        }

        return dp[s.length()][p.length()];
    }
};
