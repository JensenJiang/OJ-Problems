/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 133
 * Problem Title: Clone Graph
 * Keyword: graph, bfs, google
 *
 */

#include <vector>
#include <queue>
#include <unordered_map>
using std::vector;
using std::queue;
using std::unordered_map;
using std::make_pair;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        queue<UndirectedGraphNode *> node_queue;
        unordered_map<int, UndirectedGraphNode*> label_map;

        UndirectedGraphNode *new_head = new UndirectedGraphNode(node->label);
        label_map.insert(make_pair(node->label, new_head));

        node_queue.push(node);
        while(!node_queue.empty()) {
            UndirectedGraphNode *curr_old = node_queue.front();
            node_queue.pop();
            UndirectedGraphNode *curr_new = label_map[curr_old->label];

            for(auto i = curr_old->neighbors.begin();i != curr_old->neighbors.end();i++) {
                UndirectedGraphNode *new_nb;
                auto new_nb_ptr = label_map.find((*i)->label);
                if(new_nb_ptr != label_map.end()) new_nb = new_nb_ptr->second;
                else {
                    new_nb = new UndirectedGraphNode((*i)->label);
                    label_map[(*i)->label] = new_nb;
                    node_queue.push(*i);
                }

                curr_new->neighbors.push_back(new_nb);
            }
            
        }

        return new_head;
    }
};
