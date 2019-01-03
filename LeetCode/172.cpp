/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 172
 * Problem Title: Factorial Trailing Zeroes
 * Keyword: math
 *
 */

class Solution {
public:
    int trailingZeroes(int n) {
        if(n <= 4) return 0;
        int nr_five = 0;
        while(n > 0) {
            n /= 5;
            nr_five += n;
        }
        return nr_five;
    }
};
