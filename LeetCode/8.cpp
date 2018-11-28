/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 8
 * Problem Title: String to Integer (atoi)
 * Keyword: number, string
 *
 */

#include <string>
#include <limits>
#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()
using std::string;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        bool is_neg = false;
        int idx = 0;
        int cur_num = 0;

        while(idx < str.length() && str[idx] == ' ') idx++;
        if(idx >= str.length()) return 0;
        else if(str[idx] == '-') {
            is_neg = true;
            idx++;
        }
        else if(str[idx] == '+') idx++;
        for(;idx < str.length() && str[idx] >= '0' && str[idx] <= '9';idx++) {
            int r = str[idx] - '0';
            if(is_neg) {
                if((INT_MIN + r) / 10 <= cur_num) cur_num = cur_num * 10 - r;
                else return INT_MIN;
            }
            else {
                if(!is_neg && (INT_MAX - r) / 10 >= cur_num) {
                    cur_num = cur_num * 10 + r;
                }
                else return INT_MAX;
            }
            
        }
        return cur_num;
    }
};
