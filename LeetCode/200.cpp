/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 200
 * Problem Title: Number of Islands
 * Keyword: google, graph
 *
 */

#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class SUFS {
public:
    int nr_nodes;
    int *par;
    int *size;
    SUFS(const int n): nr_nodes(n) {
        par = new int[n];
        size = new int[n];      // after union opreation, only the root parent's value is valid
        for(int i = 0;i < n;i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    int find(const int cur) {
        if(cur == par[cur]) return cur;
        else return par[cur] = find(par[cur]);
    }

    void union_nodes(const int a, const int b) {
        int par_a = find(a), par_b = find(b);
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

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int n_row = grid.size(), n_col = grid[0].size();
        SUFS ufs(n_row * n_col);
        unordered_set<int> islands;
        int i = -1;
        for(int x = 0;x < n_row;x++) {
            for(int y = 0;y < n_col;y++) {
                i++;
                if(grid[x][y] == '0') continue;
                if(x + 1 < n_row && grid[x+1][y] == '1') {
                    ufs.union_nodes(i, i + n_col);
                }
                if(y + 1 < n_col && grid[x][y+1] == '1') {
                    ufs.union_nodes(i, i + 1);
                }
            }
        }

        i = -1;
        for(auto& row : grid) {
            for(char e : row) {
                i++;
                if(e == '0') continue;
                islands.insert(ufs.find(i));
            }
        }
        return islands.size();
    }
};
