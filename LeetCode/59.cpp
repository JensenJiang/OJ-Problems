/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 59
 * Problem Title: Spiral Matrix II
 * Keyword: 
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int curr_size = n,
            curr_num = 1;
        pair<int, int> start_coord = {0, 0},
                       curr_coord = {0, 0};

        while (curr_size > 0) {
            if (curr_size > 1) {
                curr_coord.first = start_coord.first;
                curr_coord.second = start_coord.second;
                for (int i = 0;i < curr_size - 1;i++) res[curr_coord.first][curr_coord.second++] = curr_num++;
                for (int i = 0;i < curr_size - 1;i++) res[curr_coord.first++][curr_coord.second] = curr_num++;
                for (int i = 0;i < curr_size - 1;i++) res[curr_coord.first][curr_coord.second--] = curr_num++;
                for (int i = 0;i < curr_size - 1;i++) res[curr_coord.first--][curr_coord.second] = curr_num++;
            }
            else {
                res[start_coord.first][start_coord.second] = curr_num++;
                break;
            }

            curr_size -= 2;
            start_coord.first++;
            start_coord.second++;
        }
        return res;
    }
};
