/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 763
 * Problem Title: Partition Labels
 * Keyword: good, amazon
 *
 */

/* better implementation: remove ins and outs, since we can get the information by comparing the current index to the corresponding first and last at each step */

#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0;i < S.length();i++) {
            int idx = S[i] - 'a';
            last[idx] = i;
            if(first[idx] < 0) first[idx] = i;
        }

        int curr = 0, len = 0;
        vector<int> ans;
        for(int i = 0;i < S.length();i++) {
            len++;
            int tmp = curr;
            if(first[S[i] - 'a'] == i) tmp++;
            if(last[S[i] - 'a'] == i) curr = tmp - 1;
            else curr = tmp;
            if(tmp > 0 && curr == 0) {
                ans.push_back(len);
                len = 0;
            }
        }
        return ans;
    }
};
