/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 329
 * Problem Title: Longest Increasing Path in a Matrix
 * Keyword: dp, dag
 *
 */

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        row = matrix.size();
        col = matrix[0].size();
        nums = &matrix;
        vis.resize(row);
        max_l.resize(row);
        for(int i = 0;i < row;i++) {
            vis[i].resize(col, false);
            max_l[i].resize(col, 1);
        }
        int res = 1;
        for(int i = 0;i < row;i++) {
            for(int j = 0;j < col;j++) {
                res = max(res, dp(i, j));
            }
        }
        return res;
    }
private:
    int dp(int r, int c) {
        if(vis[r][c]) return max_l[r][c];
        vis[r][c] = true;
        for(int i = 0;i < 4;i++) {
            int n_c = c + dir[i][1],
                n_r = r + dir[i][0];
            if(n_c >= 0 && n_c < col && n_r >= 0 && n_r < row && (*nums)[n_r][n_c] < (*nums)[r][c]) {
                max_l[r][c] = max(max_l[r][c], dp(n_r, n_c) + 1);
            }
        }
        return max_l[r][c];
    }
    int row, col;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> *nums;
    vector<vector<bool>> vis;
    vector<vector<int>> max_l;
};
