/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 146
 * Problem Title: LRU Cache
 * Keyword: good, design
 *
 */

#include <unordered_map>
using std::unordered_map;

struct doubleLinkedListNode {
    doubleLinkedListNode *prev, *next;
    int key, val;
    
    void self_remove() {
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }

    void insert(doubleLinkedListNode *pos) {
        this->next = pos;
        this->prev = pos->prev;
        pos->prev->next = this;
        pos->prev = this;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        /* Init double linked list */
        start.next = &end;
        end.prev = &start;

        C = capacity;
    }
    
    int get(int key) {
        auto find_res = hashmap.find(key);
        if(find_res == hashmap.end()) return -1;
        else {
            doubleLinkedListNode *curr_node = find_res->second;
            curr_node->self_remove();
            curr_node->insert(&end);
            return curr_node->val;
        }
    }
    
    void put(int key, int value) {
        auto find_res = hashmap.find(key);
        if(find_res == hashmap.end()) {
            if(hashmap.size() >= C) {
                doubleLinkedListNode *remove_node = start.next;
                remove_node->self_remove();
                hashmap.erase(remove_node->key);
                delete remove_node;
            }
            doubleLinkedListNode *ins_node = new doubleLinkedListNode;
            hashmap[key] = ins_node;
            ins_node->key = key;
            ins_node->val = value;
            ins_node->insert(&end);
        }
        else {
            doubleLinkedListNode *curr_node = find_res->second;
            curr_node->val = value;
            curr_node->self_remove();
            curr_node->insert(&end);
        }
    }
private:
    doubleLinkedListNode start, end;
    unordered_map<int, doubleLinkedListNode*> hashmap;
    int C;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
