/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 417
 * Problem Title: Pacific Atlantic Water Flow
 * Keyword: good, dp, ufs
 *
 */

#include <vector>
#include <unordered_map>
using std::vector;
using std::pair;
using std::unordered_map;

struct Edge {
    int from, to;
    int next;
    Edge(int f, int t, int _next) : from(f), to(t), next(_next) {}
};

struct Node {
    int first;
    vector<pair<int, int>> all_ids;
    Node() : first(-1) {}
};

class FStar {
public:
    vector<Node> nodes;
    vector<Edge> edges;
    FStar(const int n) {
        nodes.reserve(n);
        edges.reserve(n);
    }
    FStar() {}
    int add_node() {
        nodes.push_back(Node());
        return nodes.size() - 1;
    }
    int add_edge(int from, int to) {
        edges.push_back(Edge(from, to, nodes[from].first));
        nodes[from].first = edges.size() - 1;
        return edges.size() - 1;
    }
};

class SUFS {
public:
    int nr_nodes;
    vector<int> par;
    vector<int> size;
    SUFS(const int n): nr_nodes(n) {
        par.resize(n);
        size.resize(n);      // after union opreation, only the root parent's value is valid
        for(int i = 0;i < n;i++) {
            par[i] = i;
            size[i] = 1;        // default size as 1, can be overrided after init
        }
    }
    int find(const int cur) {
        if(cur == par[cur]) return cur;
        else return par[cur] = find(par[cur]);
    }

    void union_nodes(const int a, const int b) {
        int par_a = find(a), par_b = find(b);
        if(par_a == par_b) return;
        if(size[par_a] >= size[par_b]) {
            par[par_b] = par_a;
            size[par_a] += size[par_b];
        }
        else {
            par[par_a] = par_b;
            size[par_b] += size[par_a];
        }
    }
};

typedef pair<bool, bool> bpair;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        nr_row = matrix.size();
        nr_col = matrix[0].size();
        
        ufs = new SUFS(nr_row * nr_col);
        /* construct a DAG */
        for(int i = 0;i < nr_row;i++) {
            for(int j = 0;j < nr_col;j++) {
                for(int k = 0;k < 4;k++) {
                    int n_r = i + dir[k][0],
                        n_c = j + dir[k][1],
                        curr_num = matrix[i][j];
                    if(n_r >= 0 && n_r < nr_row && n_c >= 0 && n_c < nr_col && matrix[n_r][n_c] == curr_num) {
                        ufs->union_nodes(i * nr_col + j, n_r * nr_col + n_c);
                    }
                }
            }
        }

        for(int i = 0;i < nr_row;i++) {
            for(int j = 0;j < nr_col;j++) {
                int idx = i * nr_col + j;
                if(ufs->find(idx) == idx) {
                    dmap[idx] = G.add_node();
                }
            }
        }

        vis.resize(G.nodes.size(), false);
        state.resize(G.nodes.size(), {false, false});

        for(int i = 0;i < nr_row;i++) {
            for(int j = 0;j < nr_col;j++) {
                int idx = i * nr_col + j;
                int par = ufs->find(idx);
                int nid = dmap[par];
                G.nodes[nid].all_ids.push_back({i,j});
                int curr_num = matrix[i][j];

                if(i == 0 || j == 0) {
                    state[nid].first = true;
                }
                if(i == nr_row - 1 || j == nr_col - 1) {
                    state[nid].second = true;
                }
                for(int k = 0;k < 4;k++) {
                    int n_r = i + dir[k][0],
                        n_c = j + dir[k][1];
                    if(n_r >= 0 && n_r < nr_row && n_c >= 0 && n_c < nr_col && matrix[n_r][n_c] < curr_num) {
                        G.add_edge(nid, dmap[ufs->find(n_r * nr_col + n_c)]);
                    }
                }
            }
        }

        /* dp */
        vector<pair<int, int>> res;
        for(int i = 0;i < G.nodes.size();i++) {
            bpair temp_ret = dp(i);
            if(temp_ret.first && temp_ret.second) {
                res.insert(res.end(), G.nodes[i].all_ids.begin(), G.nodes[i].all_ids.end());
            }
        }
        return res;
    }
private:
    vector<bpair> state;
    vector<bool> vis;
    int nr_row, nr_col;
    static const int dir[4][2];
    SUFS *ufs;
    FStar G;
    unordered_map<int, int> dmap;

    bpair dp(int nid) {
        if(vis[nid]) return state[nid];
        vis[nid] = true;
        bpair res = state[nid];
        for(int e = G.nodes[nid].first;e >= 0;e = G.edges[e].next) {
            bpair temp_ret = dp(G.edges[e].to);
            res.first |= temp_ret.first;
            res.second |= temp_ret.second;
        }
        return state[nid] = res;
    }
};

const int Solution::dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
