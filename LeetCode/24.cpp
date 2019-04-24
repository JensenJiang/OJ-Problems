/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 24
 * Problem Title: Swap Nodes in Pairs
 * Keyword: linkedlist, good
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;
        ListNode **last_next = head ? &head : nullptr;
        while(curr) {
            if(!curr->next) break;
            ListNode *next = curr->next->next;
            *last_next = curr->next;
            curr->next->next = curr;
            curr->next = next;
            last_next = &curr->next;
            curr = next;
        }
        return head;
    }
};
