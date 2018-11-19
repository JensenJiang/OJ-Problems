/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 5
 * Problem Title: Longest Palindromic Substring
 * Keyword: string, good
 *
 */

#include <string>
using std::string;
using std::min;
using std::max;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return "";
        int *rad = new int[s.length() * 2 - 1];
        for(int i = 0;i < s.length() * 2 - 1;i++) rad[i] = 0;
        rad[0] = 1;

        int center = 0;
        int max_e = 0;
        int max_l = 1;
        int max_c = 0;

        for(int i = 1;i < s.length() * 2 - 1;i++) {
            if((i+1) / 2 <= max_e) rad[i] = min(rad[2 * center - i], (2 * max_e - i + 1) / 2);
            int curr = i + (i % 2 == 0 ? 2 : 1) + rad[i] * 2;
            for(;curr < s.length() * 2 - 1 && s[curr / 2] == s[i - curr / 2];curr += 2) {
                rad[i]++;
            }
            int curr_l = rad[i] * 2 + (i % 2 == 0 ? 1 : 0);
            if(curr_l > max_l) {
                max_l = curr_l;
                max_c = i;
            }
            if(curr >= s.length() * 2 - 1) break;
            if((curr - 2) / 2 > max_e) {
                max_e = (curr - 2) / 2;
                center = i;
            }
        }
        // printf("%d %d\n", max_c, max_l);
        return s.substr((max_c - max_l / 2 * 2 + 1) / 2, max_l);
    }
};

int main() {
    Solution s;
    string ret = s.longestPalindrome("abaaba");
    printf("%s\n", ret.c_str());
}
