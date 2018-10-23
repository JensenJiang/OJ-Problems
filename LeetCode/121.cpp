/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 121
 * Problem Title: Best Time to Buy and Sell Stock
 * Keyword: dp
 *
 */

#include <vector>
#include <algorithm>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int max_pf = 0;
        int min_p = prices[0];
        for(int p : prices) {
            min_p = min(min_p, p);
            max_pf = max(max_pf, p - min_p);
        }
        return max_pf;
    }
};
