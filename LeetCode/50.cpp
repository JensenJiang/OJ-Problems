/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 50
 * Problem Title: Pow(x, n)
 * Keyword: 
 *
 */

#include <cstdlib>
using namespace std;

double quick_pow(double x, long long n) {
    bool neg = (n < 0) ? true : false;
    n = abs(n);
    double res = 1.0;
    while (n > 0) {
        if (n & 1) {
            res *= x;
        }
        n >>= 1;
        x = x * x;
    }
    return neg ? 1.0 / res : res;
}

class Solution {
public:
    double myPow(double x, int n) {
        return quick_pow(x, n);
    }
};
