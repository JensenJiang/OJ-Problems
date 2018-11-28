/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 7
 * Problem Title: Reverse Integer
 * Keyword: number
 *
 */

#include <limits>
#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        bool is_neg = x < 0;
        x = is_neg ? -x : x;
        int rev = 0;
        while(x > 0) {
            int r = x % 10;
            if((INT_MAX - r) / 10 < rev) return 0;
            rev = rev * 10 + r;
            x /= 10;
        }
        return is_neg ? -rev : rev;
    }
};
