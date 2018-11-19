/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 3
 * Problem Title: Longest Substring Without Repeating Characters
 * Keyword: string
 *
 */

#include <string>
#include <unordered_set>
using std::string;
using std::unordered_set;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch_set;
        int max_len = 0;
        for(int i = 0, j = 0;j < s.length();) {
            while(j < s.length() && ch_set.find(s[j]) == ch_set.end()) {
                ch_set.insert(s[j]);
                j++;
            }
            max_len = max(max_len, j-i);
            
            if(j < s.length()) {
                while(s[i] != s[j]) {
                    ch_set.erase(s[i]);
                    i++;
                }
                i++;
                j++;
            }
        }
        return max_len;
    }
};
