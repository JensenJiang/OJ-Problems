/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 289
 * Problem Title: Game of Life
 * Keyword: google
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0;i < board.size();i++) {
            vector<int>& row = board[i];
            for(int j = 0;j < row.size();j++) {
                if(board[i][j] <= 0) continue;
                for(int dx = -1;dx <= 1;dx++) {
                    for(int dy = -1;dy <= 1;dy++) {
                        if((dx == 0 && dy == 0)) continue;
                        int x = i + dx, y = j + dy;
                        if(x < 0 || x >= board.size() || y < 0 || y >= row.size()) continue;
                        if(board[x][y] > 0) board[x][y]++;
                        else board[x][y]--;
                    }
                }
            }
        }
        for(auto& row : board) {
            for(auto& e : row) {
                if(e == -3 || e == 3 || e == 4) {
                    e = 1;
                }
                else {
                    e = 0;
                }
            }
        }
    }
};
