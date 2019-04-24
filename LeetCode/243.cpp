/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 243
 * Problem Title: Shortest Word Distance
 * Keyword: string
 *
 */

#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int latest_i1 = -1, latest_i2 = -1, min_dis = words.size();
        for(int i = 0;i < words.size();i++) {
            if(word1 == words[i]) {
                latest_i1 = i;
                if(latest_i2 >= 0 && min_dis > latest_i1 - latest_i2) min_dis = latest_i1 - latest_i2;
            }
            else if(word2 == words[i]) {
                latest_i2 = i;
                if(latest_i1 >= 0 && min_dis > latest_i2 - latest_i1) min_dis = latest_i2 - latest_i1;
            }
        }

        return min_dis;
    }
};
