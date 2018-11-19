/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 6
 * Problem Title: ZigZag Conversion
 * Keyword: string
 *
 */

#include <string>
using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string ret = "";
        for(int idx = 0;idx < s.length();idx += (2 * numRows - 2)) ret += s[idx];
        for(int i = 1;i < numRows - 1;i++) {
            for(int idx = i;idx < s.length();idx += (2 * numRows - 2)) {
                ret += s[idx];
                int temp_l = idx + 2*numRows - 2 - 2*i;
                if(temp_l < s.length()) ret += s[temp_l];
            }
        }
        for(int idx = numRows - 1;idx < s.length();idx += (2 * numRows - 2)) ret += s[idx];
        return ret;
    }
};
