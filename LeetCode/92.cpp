/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 92
 * Problem Title: Reverse Linked List II
 * Keyword: linked-list, microsoft
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode virtual_head(0);
        virtual_head.next = head;

        ListNode *prev_start = &virtual_head;
        for (int i = 0;i < m - 1;i++) prev_start = prev_start->next;

        ListNode *last = prev_start->next,
                 *curr = prev_start->next->next;
        for (int i = m + 1;i <= n;i++) {
            ListNode *next = curr->next;
            curr->next = last;
            last = curr;
            curr = next;
        }

        prev_start->next->next = curr;
        prev_start->next = last;

        return virtual_head.next;
    }
};
