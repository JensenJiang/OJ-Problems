/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 29
 * Problem Title: Divide Two Integers
 * Keyword: number
 *
 */

#include <limits>
#define int_min std::numeric_limits<int>::min()
#define int_max std::numeric_limits<int>::max()

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == int_min && divisor == -1) return int_max;

        unsigned int a = dividend < 0 ? -dividend : dividend;
        unsigned int b = divisor < 0 ? -divisor : divisor;
        bool is_neg = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);

        int k = 0;
        unsigned int curr_d = 1,
                     curr_num = b;

        while(curr_num < a) {
            curr_d <<= 1;
            curr_num <<= 1;
        }

        while(a >= b) {
            if(a >= curr_num) {
                k += curr_d;
                a -= curr_num;
            }
            curr_d >>= 1;
            curr_num >>= 1;
        }

        return is_neg ? -k : k;
    }
};
