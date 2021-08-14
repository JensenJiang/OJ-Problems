/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 54
 * Problem Title: Spiral Matrix
 * Keyword: 
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix.front().size() == 0) return {};
        vector<int> res;
        pair<int, int> coords = {0, 0};
        pair<int, int> size = {matrix.size(), matrix.front().size()};

        while (size.first > 0 && size.second > 0) {
            auto partial_res = move(get_spiral_order(matrix, coords, size));
            res.insert(res.end(), partial_res.begin(), partial_res.end());
            coords.first++;
            coords.second++;
            size.first -= 2;
            size.second -= 2;
        }
    }
private:
    vector<int> get_spiral_order(vector<vector<int>>& matrix, pair<int, int> coords, pair<int, int> size) {
        vector<int> res;
        int x = coords.first,
            y = coords.second;

        if (size.first == 1) {
            for (int i = 0;i < size.second;i++) res.push_back(matrix[x][y + i]);
        }
        else if (size.second == 1) {
            for (int i = 0;i < size.first;i++) res.push_back(matrix[x + i][y]);
        }
        else {
            for (int i = 0;i < size.second - 1;i++) res.push_back(matrix[x][y++]);
            for (int i = 0;i < size.first - 1;i++) res.push_back(matrix[x++][y]);
            for (int i = 0;i < size.second - 1;i++) res.push_back(matrix[x][y--]);
            for (int i = 0;i < size.first - 1;i++) res.push_back(matrix[x--][y]);
        }
        return res;
    }
};
