/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 22
 * Problem Title: Generate Parentheses
 * Keyword: generation
 *
 */

#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        nr = n;
        dfs("", 0, 0);
        return res;
    }
private:
    int nr;
    vector<string> res;
    void dfs(string curr_str, int used_left, int curr_sum) {
        if(used_left == nr && curr_sum == 0) res.push_back(curr_str);
        else {
            if(used_left < nr) dfs(curr_str + '(', used_left + 1, curr_sum + 1);
            if(curr_sum > 0) dfs(curr_str + ')', used_left, curr_sum - 1);
        }
    }
};
