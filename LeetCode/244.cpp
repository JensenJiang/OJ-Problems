/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 244
 * Problem Title: Shortest Word Distance II
 * Keyword: string
 *
 */

/* don't need to calculate all the possible results */

#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

class WordDistance {
public:
    WordDistance(vector<string> words) {
        vector<int> latest_i;
        for(int i = 0;i < words.size();i++) {
            auto find_res = ids.find(words[i]);
            int curr_id;
            if(find_res == ids.end()) {
                curr_id = ids.size();
                ids[words[i]] = curr_id;
                latest_i.push_back(i);
                min_dis.push_back(vector<int>(curr_id, words.size()));
            }
            else {
                curr_id = find_res->second;
                latest_i[curr_id] = i;
            }

            for(int j = 0;j <= curr_id - 1;j++) {
                if(i - latest_i[j] < min_dis[curr_id][j]) min_dis[curr_id][j] = i - latest_i[j];
            }
            for(int j = curr_id + 1;j < latest_i.size();j++) {
                if(i - latest_i[j] < min_dis[j][curr_id]) min_dis[j][curr_id] = i - latest_i[j];
            }
        }
    }
    
    int shortest(string word1, string word2) {
        int id1 = ids[word1],
            id2 = ids[word2];
        if(id1 < id2) return min_dis[id2][id1];
        else return min_dis[id1][id2];
    }
private:
    unordered_map<string, int> ids;
    vector<vector<int>> min_dis;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
