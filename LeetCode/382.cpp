/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 382
 * Problem Title: Linked List Random Node
 * Keyword: random
 *
 */

#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        lhead = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = -1, cnt = 0;
        for(ListNode *curr = lhead;curr != nullptr;curr = curr->next) {
            cnt++;
            if(rand() % cnt == 0) res = curr->val;
        }
        return res;
    }
private:
    ListNode *lhead;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
