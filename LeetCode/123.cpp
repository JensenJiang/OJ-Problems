/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 123
 * Problem Title: Best Time to Buy and Sell Stock III
 * Keyword: dp, hard, good
 *
 */

#include <vector>
#include <limits>
#include <algorithm>
#include <cstdio>
using std::vector;
using std::min;
using std::max;

struct data_info {
    int s;
    int e;
    int get_p() {
        return e - s;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        if(prices.size() == 0 || k == 0) return 0;
        vector<data_info> incs = findInc(prices);
        for(auto t : incs) {
            printf("%d %d\n",t.s, t.e);
        }
        if(incs.size() <= k) {
            int sum = 0;
            for(auto d : incs) {
                sum += (d.e - d.s);
            }
            return sum;
        }

        int curr_idx = 0;
        int *min_s = new int[k+1];
        int *max_gb = new int[k+1];
        int *global_max[2];
        for(int i = 0;i < 2;i++) {
            global_max[i] = new int[k+1];
            for(int j = 0;j <= k;j++) global_max[i][j] = 0;
        }
        global_max[0][0] = 0;
        global_max[0][1] = incs[0].get_p();
        for(int i = 0;i <= k;i++) min_s[i] = int_max;
        min_s[0] = incs[0].s;
        for(int i = 0;i <= k;i++) max_gb[i] = 0;

        for(int i = 1;i < incs.size();i++) {
            for(int j = 0;j <= min(k, i);j++) {
                min_s[j] = min(min_s[j], incs[i].s);
                if(max_gb[j] - min_s[j] < global_max[curr_idx][j] - incs[i].s) {
                    max_gb[j] = global_max[curr_idx][j];
                    min_s[j] = incs[i].s;
                }
            }

            global_max[curr_idx^1][0] = 0;
            for(int j = 1;j <= min(k, i+1);j++) {
                global_max[curr_idx^1][j] = max(global_max[curr_idx][j], incs[i].e + max_gb[j - 1] - min_s[j - 1]);
            }
            curr_idx ^= 1;
        }

        return global_max[curr_idx][k];
    }
private:
    static int int_max;
    vector<data_info> findInc(vector<int>& prices) {
        vector<data_info> ret;
        int new_s;
        for(int i = 0;i < prices.size() - 1;) {
            while(i < prices.size() - 1 && prices[i] > prices[i+1]) i++;
            if(i < prices.size() - 1) new_s = prices[i];
            else break;
            while(i < prices.size() - 1 && prices[i] <= prices[i+1]) i++;
            ret.push_back({new_s, prices[i]});
            i++;
            
        }
        return ret;
    }
};

int Solution::int_max = std::numeric_limits<int>::max();
