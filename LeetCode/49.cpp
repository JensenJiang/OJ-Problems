/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 49
 * Problem Title: Group Anagrams
 * Keyword: string
 *
 */

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group_map;
        
        for (const string& str : strs) {
            group_map[generate_key(str)].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& kv : group_map) {
            res.push_back(move(kv.second));
        }

        return res;
    }
private:
    string generate_key(const string& str) {
        vector<int> char_cnt(26, 0);
        for (char c : str) {
            char_cnt[c - 'a']++;
        }

        string key;
        for (int i = 0;i < 26;i++) {
            if (char_cnt[i] > 0) {
                key += ('a' + i);
                if (char_cnt[i] > 1) {
                    key += to_string(char_cnt[i]);
                }
            }
        }
        return key;
    }
};
