/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 206
 * Problem Title: Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        notNullReverseList(head);
        return new_head;
    }
private:
    ListNode *new_head;
    ListNode* notNullReverseList(ListNode *head) {
        if (head->next) {
            notNullReverseList(head->next);
            head->next = head;
        }
        else new_head = head;
        return head;
    }
};
