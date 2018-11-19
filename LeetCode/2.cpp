/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 2
 * Problem Title: Add Two Numbers
 * Keyword: big-number
 *
 */

#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

inline int get_val(ListNode* const ptr) {
    return ptr ? ptr->val : 0;
}

inline ListNode* get_next(ListNode *curr) {
    return curr ? curr->next : nullptr;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = nullptr;
        ListNode *curr = nullptr;
        int addition = 0;
        
        for(ListNode *curr1 = l1, *curr2 = l2;curr1 || curr2;curr1 = get_next(curr1), curr2 = get_next(curr2)) {
            addition += get_val(curr1) + get_val(curr2);
            if(!curr) {
                ret = new ListNode(addition % 10);
                curr = ret;
            }
            else {
                curr->next = new ListNode(addition % 10);
                curr = curr->next;
            }
            addition /= 10;
        }
        if(addition) {
            curr->next = new ListNode(addition % 10);
        }
        return ret;
    }
};
