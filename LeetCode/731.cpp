/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 731
 * Problem Title: My Calendar II
 * Keyword: google, good
 *
 */

/* Maintain the booking times of each intervals */

#include <vector>
#include <algorithm>
using std::pair;
using std::vector;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& p : double_booking) {
            if (p.first < end && start < p.second) return false;
        }
        for (const auto& event : events) {
            if (event.first < end && start < event.second) {
                double_booking.push_back({std::max(event.first, start), std::min(event.second, end)});
            }
        }

        events.push_back({start, end});
        return true;
    }
private:
    vector<pair<int, int>> events;
    vector<pair<int, int>> double_booking;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
