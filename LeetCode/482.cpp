/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 482
 * Problem Title: License Key Formatting
 * Keyword: string, google
 *
 */

#include <string>
using std::string;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ret = "";
        int nr_valid_ch = 0;
        for(char c : S) if(c != '-') nr_valid_ch++;
        int nr_groupchs = (nr_valid_ch % K == 0) ? K : nr_valid_ch % K;

        for(char c : S) {
            if(c == '-') continue;
            if(nr_groupchs == 0) {
                nr_groupchs = K;
                ret += '-';
            }
            nr_groupchs--;
            ret += (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
        }

        return ret;
    }
};
