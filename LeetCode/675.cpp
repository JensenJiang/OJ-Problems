/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 675
 * Problem Title: Cut Off Trees for Golf Event
 * Keyword: bfs
 *
 */
/* optimized bfs: hadlock algorithm */

#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::sort;
using std::pair;

struct Tree {
    int h;
    int x, y;
    bool operator <(const Tree& a) const{
        return h < a.h;
    }
};

struct Coordinate {
    int x, y;
};

auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<Tree> trees;
        for(int i = 0;i < forest.size();i++) {
            for(int j = 0;j < forest[0].size();j++) {
                if(forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());

        int tot = 0;
        for(const Tree& t : trees) {
            int dis = move_to({t.x, t.y}, forest);
            if(dis < 0) return -1;
            else tot += dis;
            curr = {t.x, t.y};
        }

        return tot;
    }
private:
    Coordinate curr = {0, 0};
    static const int dir[4][2];
    int move_to(const Coordinate& to, const vector<vector<int>>& m) {
        if(curr.x == to.x && curr.y == to.y) return 0;
        bool vis[50][50];
        int size_x = m.size(), size_y = m[0].size();
        for(int i = 0;i < size_x;i++) {
            for(int j = 0;j < size_y;j++) {
                vis[i][j] = false;
            }
        }
        queue<pair<Coordinate, int>> q;
        q.push({curr, 0});
        vis[curr.x][curr.y] = true;
        while(!q.empty()) {
            Coordinate curr_c = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for(int i = 0;i < 4;i++) {
                Coordinate new_c = {curr_c.x + dir[i][0], curr_c.y + dir[i][1]};
                if(new_c.x == to.x && new_c.y == to.y) return dis + 1;
                if(new_c.x >= 0 && new_c.x < size_x && new_c.y >= 0 && new_c.y < size_y && !vis[new_c.x][new_c.y] && m[new_c.x][new_c.y] > 0) {
                    q.push({new_c, dis + 1});
                    vis[new_c.x][new_c.y] = true;
                }
            }
        }
        return -1;
    }
};

const int Solution::dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
