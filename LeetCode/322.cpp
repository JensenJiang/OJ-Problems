/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 322
 * Problem Title: Coin Change
 * Keyword: dp
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> min_coins(amount + 1, -1);
        min_coins[0] = 0;
        for(int c : coins) {
            for(int i = 0;i <= amount - c;i++) {
                if(min_coins[i] >= 0 && (min_coins[i + c] == -1 || min_coins[i + c] > min_coins[i] + 1)) min_coins[i + c] = min_coins[i] + 1;
            }
        }
        return min_coins[amount];
    }
};
