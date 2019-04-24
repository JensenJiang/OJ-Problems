#include <vector>
using std::vector;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        dis_K = K;
        for(int i = 1;i <= 9;i++) dfs(i, i, N - 1);
        return ans;
    }
private:
    void dfs(int last_num, int last_digit, int rest_len) {
        if(rest_len == 0) ans.push_back(last_num);
        else {
            if(last_digit - dis_K >= 0) dfs(last_num * 10 + last_digit - dis_K, last_digit - dis_K, rest_len - 1);
            if(dis_K != 0 && last_digit + dis_K <= 9) dfs(last_num * 10 + last_digit + dis_K, last_digit + dis_K, rest_len - 1);
        }
    }
    int dis_K;
    vector<int> ans;
};
