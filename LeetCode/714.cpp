/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 714
 * Problem Title: Best Time to Buy and Sell Stock with Transaction Fee
 * Keyword: dp
 *
 */

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int v_size = prices.size();
        if(v_size == 0 || v_size == 1) return 0;

        local = new int[v_size];
        global = new int[v_size];
        local[0] = -fee;
        global[0] = 0;

        for(int i = 1;i < v_size;i++) {
            local[i] = max(global[i-1], local[i-1] + fee) + prices[i] - prices[i-1] - fee;
            global[i] = max(global[i-1], local[i]);
        }

        return global[v_size-1];
    }
private:
    int *local, *global;
};
