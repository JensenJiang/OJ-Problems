/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 231
 * Problem Title: Power of Two
 * Keyword: bit
 *
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        else return (n^(n&(-n))) == 0;
    }
};
