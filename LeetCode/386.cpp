/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 386
 * Problem Title: Lexicographical Numbers
 * Keyword: generation, number
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n == 0) return {};
        max_n = n;
        dfs(1);
        return res;
    }
private:
    int max_n;
    vector<int> res;
    void dfs(int v) {
        for(int i = v % 10;i <= 9;i++) {
            if(v <= max_n) {
                res.push_back(v);
                if(v * 10 <= max_n) dfs(v * 10);
            }
            else break;
            v++;
        }
    }
};
