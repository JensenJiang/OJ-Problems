/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 731
 * Problem Title: My Calendar II
 * Keyword: google, good
 *
 */

/* Maintain the booking times of each intervals */

#include <list>
using std::list;

struct Interval {
    int l, r, times;
};

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        if (start == end) return true;
        if (intervals.empty()) {
            intervals.push_back(Interval{start, end, 1});
            return true;
        }
        else {
            list<Interval>::iterator l_iter = intervals.begin(),
                                     r_iter = intervals.begin();
            for (;l_iter != intervals.end();l_iter++) {
                if (start < l_iter->r) {
                    break;
                }
            }

            for (;r_iter != intervals.end();r_iter++) {
                if (end <= r_iter->r) {
                    break;
                }
            }

            if (l_iter == r_iter && (r_iter == intervals.end() || r_iter->l >= end)) {
                intervals.insert(l_iter, {start, end ,1});
                return true;
            }
            else {
                for (auto i = l_iter;i != r_iter;i++) {
                    if (i->times >= 2) return false;
                }
                if (r_iter != intervals.end() && end > r_iter->l && r_iter->times >= 2) return false;

                if (start < l_iter->l) {
                    intervals.insert(l_iter, {start, l_iter->l, 1});
                }
                else if (start > l_iter->l) {
                    intervals.insert(l_iter, {l_iter->l, start, l_iter->times});
                    l_iter->l = start;
                }

                if (l_iter != r_iter) {
                    l_iter->times++;
                    for (auto i = std::next(l_iter, 1);i != r_iter;i++) {
                        i->times++;
                        auto prev_iter = std::prev(i, 1);
                        if (prev_iter->r < i->l) {
                            intervals.insert(i, {prev_iter->r, i->l, 1});
                        }
                    }
                }

                if (r_iter == intervals.end() || end <= r_iter->l) {
                    intervals.insert(r_iter, {(std::prev(r_iter, 1))->r, end, 1});
                }
                else{
                    if (r_iter != intervals.begin() && r_iter != l_iter){
                        auto prev_iter = std::prev(r_iter, 1);
                        if (prev_iter->r < r_iter->l) {
                            intervals.insert(r_iter, {prev_iter->r, r_iter->l, 1});
                        }
                    }
                    
                    if (end < r_iter->r) {
                        intervals.insert(r_iter, {r_iter->l, end, r_iter->times + 1});
                        r_iter->l = end;
                    }
                    else {
                        r_iter->times++;
                    }
                }
                return true;
            }
        }
    }
private:
    list<Interval> intervals;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
