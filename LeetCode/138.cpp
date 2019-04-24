/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 138
 * Problem Title: Copy List with Random Pointer
 * Keyword: linkedlist
 *
 */
/* another solution: use the next pointer in the old node to store the new clone node */

#include <unordered_map>
using std::unordered_map;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for(RandomListNode *curr = head;curr != nullptr;curr = curr->next) {
            RandomListNode *curr_new = add_new(curr);
            curr_new->next = add_new(curr->next);
            curr_new->random = add_new(curr->random);
        }
        return head ? new_map[head] : nullptr;
    }
private:
    unordered_map<RandomListNode*, RandomListNode*> new_map;
    RandomListNode* add_new(RandomListNode *old) {
        if(old == nullptr) return nullptr;
        auto find_res = new_map.find(old);
        if(find_res == new_map.end()) {
            find_res = new_map.insert({old, new RandomListNode(old->label)}).first;
        }
        return find_res->second;
    }
};
