/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 128
 * Problem Title: Longest Consecutive Sequence
 * Keyword: ufs, hash, google
 *
 */

#include <vector>
#include <set>
#include <algorithm>
using std::vector;
using std::set;
using std::max;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        set<int> s = set<int>(nums.begin(), nums.end());
        int curr_len = 1, max_len = 1;
        auto i = s.begin();
        int last_num = *i;
        for(i++;i != s.end();i++) {
            if(*i != last_num + 1) {
                max_len = max(max_len, curr_len);
                curr_len = 1;
            }
            else {
                curr_len++;
            }
            last_num = *i;
        }
        max_len = max(max_len, curr_len);
        return max_len;
    }
};
