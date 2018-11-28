/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 9
 * Problem Title: Palindrome Number
 * Keyword: number, string
 *
 */

#include <string>
using std::string;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string str_int = std::to_string(x);
        for(int i = 0,j = str_int.length() - 1;i < j;i++, j--) {
            if(str_int[i] != str_int[j]) return false;
        }
        return true;
    }
};
