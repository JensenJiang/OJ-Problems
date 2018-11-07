/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 399
 * Problem Title: Evaluate Division
 * Keyword: google, graph
 *
 */

#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
using std::vector;
using std::pair;
using std::make_pair;
using std::string;
using std::unordered_map;
#define eps 1e-9

struct Node {
    bool vis;
    unordered_map<string, pair<bool, double>> edges;
};

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for(int i = 0;i < equations.size();i++) {
            string s1 = equations[i].first, s2 = equations[i].second;
            if(nodes.find(s1) == nodes.end()) {
                nodes[s1] = new Node;
            }
            if(nodes.find(s2) == nodes.end()) {
                nodes[s2] = new Node;
            }

            nodes[s1]->edges[s2] = make_pair(true, values[i]);
            if(fabs(values[i]) >= eps) {
                nodes[s2]->edges[s1] = make_pair(true, 1.0 / values[i]);
            }
        }

        vector<double> ret;

        for(auto q : queries) {
            if(nodes.find(q.first) == nodes.end() || nodes.find(q.second) == nodes.end()) ret.push_back(-1.0);
            else if(q.first == q.second) ret.push_back(1.0);
            else {
                set_unvisit();
                auto res = dfs(q.first, q.second);
                ret.push_back(res.second);
            }
        }
        return ret;
    }
private:
    unordered_map<string, Node*> nodes;
    void set_unvisit() {
        for(auto e : nodes) {
            e.second->vis = false;
        }
    }

    pair<bool, double> dfs(string from, string to) {
        // printf("In <%s,%s>\n", from.c_str(), to.c_str());
        Node *curr_node = nodes[from];
        curr_node->vis = true;
        auto target = curr_node->edges.find(to);
        if(target != curr_node->edges.end()) return target->second;
        else {
            for(auto e : curr_node->edges) {
                Node *next_node = nodes[e.first];
                if(e.second.first && !next_node->vis) {
                    auto res = dfs(e.first, to);
                    if(res.first) {
                        double new_res = res.second * e.second.second;
                        curr_node->edges[to] = make_pair(true, new_res);
                        if(fabs(new_res) >= eps) {
                            nodes[to]->edges[from] = make_pair(true, 1.0 / new_res);
                        }
                        return curr_node->edges[to];
                    }
                }
            }
        }
        curr_node->edges[to] = make_pair(false, -1.0);
        return curr_node->edges[to];
    }
};

int main() {
    Solution s;
    vector<double> values{3.0, 0.5, 3.4, 5.6};
    vector<double> res = s.calcEquation({make_pair("x1", "x2"), make_pair("x2", "x3"), make_pair("x1", "x4"), make_pair("x2", "x5")}, values, {make_pair("x2", "x4"), make_pair("x1", "x5"), make_pair("x1", "x3"), {"x5", "x5"}, {"x5", "x1"}, {"x3", "x4"}, {"x4", "x3"}});
    for(double v : res) printf("%f\n", v);
}
