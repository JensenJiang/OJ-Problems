/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 25
 * Problem Title: Reverse Nodes in k-Group
 * Keyword: linkedlist, good
 *
 */

#include <stack>
using std::stack;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode vhead = ListNode(0);
        vhead.next = head;
        ListNode *last = &vhead;
        ListNode *curr = head;
        stack<ListNode*> to_rev;
        while(true) {
            while(curr && to_rev.size() < k) {
                to_rev.push(curr);
                curr = curr->next;
            }
            if(to_rev.size() < k) break;
            curr = to_rev.top()->next;
            while(!to_rev.empty()) {
                ListNode *next = to_rev.top();
                to_rev.pop();
                last->next = next;
                last = next;
            }
            last->next = curr;
        }
        return vhead.next;
    }
};
