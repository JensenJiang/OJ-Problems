/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 19
 * Problem Title: Remove Nth Node From End of List
 * Keyword: linkedlist, good
 *
 */

/* Do this in one pass */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode n_head(0);
        n_head.next = head;
        ListNode *f_ptr = &n_head,
                 *s_ptr = &n_head;
        for(int i = 0;i < n;i++) f_ptr = f_ptr->next;
        while(f_ptr->next) {
            f_ptr = f_ptr->next;
            s_ptr = s_ptr->next;
        }
        s_ptr->next = s_ptr->next->next;
        return n_head.next;
    }
};
