/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 244
 * Problem Title: Shortest Word Distance II
 * Keyword: string
 *
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
using std::vector;
using std::string;
using std::unordered_map;
using std::min;

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i = 0;i < words.size();i++) {
            ids[words[i]].push_back(i);
        }
        max_dis = words.size();
    }
    
    int shortest(string word1, string word2) {
        const vector<int>& ids1 = ids[word1];
        const vector<int>& ids2 = ids[word2];
        int i = 0, j = 0;
        int min_dis = max_dis;

        while(i < ids1.size() && j < ids2.size()) {
            min_dis = min(min_dis, abs(ids1[i] - ids2[j]));
            if(ids1[i] < ids2[j]) i++;
            else j++;
        }
        return min_dis;
    }
private:
    unordered_map<string, vector<int>> ids;
    int max_dis;
};
