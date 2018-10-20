/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 21
 * Problem Title: Merge Two Sorted Lists
 * Keyword: recursive
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *curr = nullptr;
        head = min_create(l1, l2);
        curr = head;
        while(l1 != nullptr || l2 != nullptr) {
            curr->next = min_create(l1, l2);
            curr = curr->next;
        }
        return head;
    }
private:
    static ListNode* min_create(ListNode*& l1, ListNode*& l2) {
        ListNode *new_node;
        if(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                new_node = new ListNode(l1->val);
                l1 = l1->next;
                return new_node;
            }
            else {
                new_node = new ListNode(l2->val);
                l2 = l2->next;
                return new_node;
            }
        }
        else if(l1 != nullptr) {
            new_node = new ListNode(l1->val);
            l1 = l1->next;
            return new_node;
        }
        else if(l2 != nullptr) {
            new_node = new ListNode(l2->val);
            l2 = l2->next;
            return new_node;
        }
        else return nullptr;
    }
};
