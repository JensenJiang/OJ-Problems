/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 57
 * Problem Title: Insert Interval
 * Keyword: 
 *
 */

/* Better solution: use equal_range, done in O(logn), https://leetcode.com/problems/insert-interval/discuss/21599/Elegant-C%2B%2B-STL-solution-using-%22equal_range%22-to-find-overlapped-intervals. */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto curr = intervals.begin();
        vector<vector<int>> res;

        while (curr != intervals.end() && curr->at(1) < newInterval[0]) {
            res.push_back(*curr);
            curr++;
        }

        int l = newInterval[0],
            r = newInterval[1];

        while (curr != intervals.end() && curr->at(0) <= newInterval[1]) {
            l = min(l, curr->at(0));
            r = max(r, curr->at(1));
            curr++;
        }
        res.push_back({l, r});

        res.insert(res.end(), curr, intervals.end());
        return res;
    }
};
