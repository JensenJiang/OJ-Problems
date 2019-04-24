/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 26
 * Problem Title: Remove Duplicates from Sorted Array
 * Keyword: in_place
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unsigned int next = 0,
                     head = 0,
                     tail;

        while(head < nums.size()) {
            for(tail = head + 1;tail < nums.size() && nums[head] == nums[tail];tail++);
            nums[next] = nums[head];

            next++;
            head = tail;
        }

        return next;
    }
};
