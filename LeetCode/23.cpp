/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 23
 * Problem Title: Merge k Sorted Lists
 * Keyword: google, sort
 *
 */

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct my_comp {
    bool operator()(ListNode* const& a, ListNode* const& b) {
        return a->val >= b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode ph_head(0);
        ListNode *curr_head = &ph_head;
        priority_queue<ListNode*, vector<ListNode*>, my_comp> head_queue;
        for(auto i : lists) {
            if(i != nullptr) head_queue.push(i);
        }

        while(!head_queue.empty()) {
            ListNode *curr = head_queue.top();
            head_queue.pop();
            curr_head->next = curr;
            curr_head = curr;

            if(curr->next != nullptr) head_queue.push(curr->next);
        }

        return ph_head.next;
    }
};
