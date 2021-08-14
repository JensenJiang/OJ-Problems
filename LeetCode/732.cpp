/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 732
 * Problem Title: My Calendar III
 * Keyword: google, good, hard
 *
 */

/* Better code: https://leetcode.com/problems/my-calendar-iii/discuss/176950/C%2B%2B-Map-Solution-beats-95%2B */

#include <map>
using std::map;
using std::max;

class MyCalendarThree {
public:
    MyCalendarThree() : k(0){
    }
    
    int book(int start, int end) {
        if (calendar.empty()) {
            calendar[start] = 1;
            calendar[end] = 0;
            k = 1;
        }
        else {
            auto iter = calendar.upper_bound(start);
            if (iter == calendar.begin()) {
                calendar[start] = 1;
            }
            else {
                auto prev_iter = std::prev(iter);
                if (prev_iter->first == start) {
                    prev_iter->second++;
                    k = max(k, prev_iter->second);
                }
                else {
                    calendar[start] = prev_iter->second + 1;
                    k = max(k, prev_iter->second + 1);
                }
            }
            for (;iter != calendar.end() && iter->first < end;iter++) {
                iter->second++;
                k = max(k, iter->second);
            }

            if (iter == calendar.end()) {
                calendar[end] = 0;
            }
            else if (iter->first > end) {
                auto prev_iter = std::prev(iter);
                calendar[end] = prev_iter->second - 1;
            }
        }
        return k;
    }
private:
    map<int, int> calendar;
    int k;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
