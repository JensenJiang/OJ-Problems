/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 28
 * Problem Title: Implement strStr()
 * Keyword: string
 *
 */

#include <string>
using std::string;

class KMPMatcher {
public:
    string pattern;
    int *bw;
    KMPMatcher(const string& p) {
        pattern = p;
        bw = new int[p.length() + 1];
        bw[0] = -1;
        for(int i = 0, j = bw[0];i < p.length();) {
            while(j >= 0 && p[i] != p[j]) j = bw[j];
            i++;
            j++;
            bw[i] = j;
        }
    }

    int search_first(const string& s) {
        for(int i = 0, j = 0;i < s.length();) {
            while(j >= 0 && pattern[j] != s[i]) j = bw[j];
            i++;
            j++;
            if(j == pattern.length()) {
                return i - j;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        KMPMatcher kmp(needle);
        return kmp.search_first(haystack);
    }
};
