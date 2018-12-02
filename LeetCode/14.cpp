/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 14
 * Problem Title: Longest Common Prefix
 * Keyword: string
 *
 */

#include <vector>
#include <string>
using std::vector;
using std::string;
using std::min;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int min_len = strs[0].length();
        for(string const& str : strs) min_len = min((int) str.length(), min_len);
        string ret = "";
        for(int i = 0;i < min_len;i++) {
            for(int j = 0;j < strs.size() - 1;j++) if(strs[j][i] != strs[j+1][i]) return ret;
            ret += strs[0][i];
        }
        return ret;
    }
};
