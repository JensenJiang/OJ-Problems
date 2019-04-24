#include <vector>
#include <iostream>
#include <stack>
#include <random>
#include <algorithm>
using std::cin;
using std::cout;
using std::getline;
using std::endl;
using std::vector;
using std::stack;
using std::mt19937;
using std::random_device;
using std::shuffle;

random_device rd;
mt19937 gen(rd());

class Graph {
public:
    int nr_nodes;
    vector<vector<int>> E;
    vector<vector<int>> D;
    vector<bool> vis;
    stack<int> path;
    Graph(int n) {
        E.resize(n);
        D.resize(n);
        nr_nodes = n;
    }
    void add_edge(int u, int v) {
        E[u].push_back(v);
        E[v].push_back(u);
    }

    void add_disjoint(int u, int v) {
        D[u].push_back(v);
        D[v].push_back(u);
    }

    bool search_hmpath() {
        vector<int> order;
        for (int i = 0;i < nr_nodes;i++) order.push_back(i);
        shuffle(order.begin(), order.end(), gen);
        for (int i : order) {
            vis.clear();
            vis.resize(nr_nodes, false);
            bool success = false;
            dfs(i, success, 0);
            if (success) return true;
        }
        return false;
    }
    void dfs(int curr, bool& success, int curr_n) {
        vis[curr] = true;
        curr_n += 1;
        if (curr_n == nr_nodes) {
            path.push(curr);
            success = true;
            vis[curr] = false;
            return;
        }
        for (int next : E[curr]) {
            if (!vis[next]) dfs(next, success, curr_n);
            if (success) {
                path.push(curr);
                return;
            }
        }
        vis[curr] = false;
        return;
    }
};


int main() {
    int T;
    cin >> T;

    for (int t = 1;t <= T;t++) {
        int R, C;
        cin >> R >> C;
        Graph G(R * C);
        for (int i = 0;i < R * C;i++) {
            int r1 = i / C,
                c1 = i % C;

            for (int j = i + 1;j < R * C;j++) {
                int r2 = j / C,
                    c2 = j % C;

                if (r1 == r2 || c1 == c2 || r1 - c1 == r2 - c2 || r1 + c1 == r2 + c2) {
                    G.add_disjoint(i, j);
                }
                else G.add_edge(i, j);
            }
        }
        for (int i = 0;i < R * C;i++) {
            shuffle(G.E[i].begin(), G.E[i].end(), gen);
        }
        cout << "Case #" << t << ": ";
        if(G.search_hmpath()) {
            cout << "POSSIBLE" << endl;
            while (!G.path.empty()) {
                int id = G.path.top();
                G.path.pop();
                cout << id / C + 1 << " " << id % C + 1 << endl;
            }
        }
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
