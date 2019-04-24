/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 344
 * Problem Title: Reverse String
 * Keyword: string
 *
 */

#include <string>
using std::string;

class Solution {
public:
    string reverseString(string s) {
        for(int i = 0, j = s.length() - 1;i < j;i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
};
