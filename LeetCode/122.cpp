/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 122
 * Problem Title: Best Time to Buy and Sell Stock II
 * Keyword:
 *
 */

#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int tot_pf = 0;
        int min_p = prices[0], last_p = prices[0];

        for(int p : prices) {
            if(p < last_p) {
                tot_pf += (last_p - min_p);
                min_p = p;
            }
            last_p = p;
        }
        tot_pf += (last_p - min_p);
        return tot_pf;
    }
};
