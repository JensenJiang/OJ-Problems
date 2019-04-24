/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 127
 * Problem Title: Word Ladder
 * Keyword: bfs, string
 *
 */

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using std::string;
using std::vector;
using std::queue;
using std::unordered_set;
using std::pair;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> str_set;
        for(const string& s : wordList) str_set.insert(s);
        if(str_set.find(endWord) == str_set.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()) {
            string curr_str = q.front().first;
        int step = q.front().second;
            q.pop();
            for(int i = 0;i < curr_str.length();i++) {
                char ori_c = curr_str[i];
                for(char c = 'a';c <= 'z';c++) {
                    if(c == ori_c) continue;
                    curr_str[i] = c;
                    auto find_res = str_set.find(curr_str);
                if(find_res != str_set.end()) {
                        if(curr_str == endWord) return step + 1;
                        q.push({curr_str, step + 1});
                        str_set.erase(find_res);
                    }
                }
                curr_str[i] = ori_c;
            }
        }

        return 0;
    }
};
