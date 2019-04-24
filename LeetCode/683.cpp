/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 683
 * Problem Title: K Empty Slots
 * Keyword: good, google, hard, monotone-queue
 *
 */

#include <vector>
#include <stack>
#include <limits>
using std::vector;
using std::stack;
using std::min;

const int int_max = std::numeric_limits<int>::max();

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int vec_size = flowers.size();
        vector<int> pos_dates(vec_size, 0);
        stack<int> dates;
        int min_date = int_max;

        for(int i = 0;i < vec_size;i++) {
            pos_dates[flowers[i] - 1] = i;
        }
        for(int i = 0;i < vec_size;i++) {
            int curr_date = pos_dates[i],
                last = -1;
            while(!dates.empty() && dates.top() > curr_date) {
                last = dates.top();
                if(i - flowers[last] == k) min_date = min(min_date, last + 1);
                dates.pop();
            }
            if(!dates.empty()) {
                int pre_date = dates.top();
                if(i - flowers[pre_date] == k) min_date = min(min_date, curr_date + 1);
            }
            dates.push(curr_date);
        }
        return min_date == int_max ? -1 : min_date;
    }
};
