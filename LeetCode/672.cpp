/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 672
 * Problem Title: Bulb Switcher II
 * Keyword: microsoft, math
 *
 */

class Solution {
public:
    int flipLights(int n, int m) {
        if(n == 0) return 0;
        if(m == 0) return 1;
        int s[3][4] = {
            {2, 2, 2, 2},
            {3, 4, 4, 4},
            {4, 7, 8, 8},
        };
        if(n >= 3) n = 3;
        if(m >= 4) m = 4;
        return s[n-1][m-1];
    }
};
