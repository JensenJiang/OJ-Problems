/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 56
 * Problem Title: Merge Intervals
 * Keyword: google
 *
 */

#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
using std::max;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool Interval_comp(Interval const& a, Interval const& b) {
    if(a.start == b.start) return a.end < b.end;
    else return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return {};

        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), Interval_comp);
        Interval curr = intervals[0];
        for(int i = 1;i < intervals.size();i++) {
            if(intervals[i].start > curr.end) {
                ret.push_back(curr);
                curr = intervals[i];
            }
            else {
                curr.end = max(curr.end, intervals[i].end);
            }
        }
        ret.push_back(curr);
        return ret;
    }
};
