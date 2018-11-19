/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 13
 * Problem Title: Roman to Integer
 * Keyword:
 *
 */

#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for(int i = 0;i < s.length();) {
            if(i < s.length() - 1 && ro_ctoi[s[i]] < ro_ctoi[s[i+1]]) {
                ret += (ro_ctoi[s[i+1]] - ro_ctoi[s[i]]);
                i += 2;
            }
            else {
                ret += ro_ctoi[s[i]];
                i++;
            }
        }
        return ret;
    }
private:
    static unordered_map<char, int> ro_ctoi;
};

unordered_map<char, int> Solution::ro_ctoi = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
