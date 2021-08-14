/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 445
 * Problem Title: Add Two Numbers II
 * Keyword: microsoft
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1 = make_stack(l1),
                         st2 = make_stack(l2);

        ListNode *last = nullptr;
        int sum = 0;
        while (!(st1.empty() && st2.empty())) {
            if (!st1.empty()) {
                sum += st1.top()->val;
                st1.pop();
            }
            if (!st2.empty()) {
                sum += st2.top()->val;
                st2.pop();
            }

            last = make_new_node(last, sum);
        }

        if (sum > 0) last = make_new_node(last, sum);

        return last;
    }
private:
    stack<ListNode*> make_stack(ListNode* l) {
        stack<ListNode*> st;
        for (ListNode *curr = l;curr != nullptr;curr = curr->next) st.push(curr);
        return st;
    }

    ListNode* make_new_node(ListNode *last, int& sum) {
        ListNode *new_node = new ListNode(sum % 10);
        sum /= 10;
        new_node->next = last;
        return new_node;
    }
};
