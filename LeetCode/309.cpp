/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 309
 * Problem Title: Best Time to Buy and Sell Stock with Cooldown
 * Keyword: dp
 *
 */

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;

        local = new int[prices.size()];
        global = new int[prices.size()];
        local[0] = 0;
        global[0] = 0;
        
        for(int i = 1;i < prices.size();i++) {
            local[i] = max(i >= 3 ? global[i-3] : 0, local[i-1]) + prices[i] - prices[i-1];
            global[i] = max(local[i], global[i-1]);
        }

        return global[prices.size()-1];
    }
private:
    int *local, *global;
};
