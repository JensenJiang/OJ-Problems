/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 58
 * Problem Title: Length of Last Word
 * Keyword: string
 *
 */

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        auto i = s.rbegin();
        while (i != s.rend() && *i == ' ') i++;
        for (;i != s.rend() && *i != ' ';i++, res++);
        return res;
    }
};
