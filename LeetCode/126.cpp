/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 126
 * Problem Title: Word Ladder II
 * Keyword: bfs, good
 *
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using std::string;
using std::vector;
using std::queue;
using std::unordered_map;

struct Node {
    int d;
    vector<string> from_strs;
    Node(int _d) : d(_d){}
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(const string& s : wordList) str_map.insert({s, Node(0)});
        if(str_map.find(endWord) == str_map.end()) return {};
        str_map.insert({beginWord, Node(1)});

        queue<string> q;
        q.push(beginWord);
        bool found = false;

        for(int curr_d = 1;!q.empty();curr_d++) {
            int q_size = q.size();
            for(int i = 0;i < q_size;i++) {
                string curr_str = q.front();
                for(int i = 0;i < curr_str.length();i++) {
                    char ori_c = curr_str[i];
                    for(char c = 'a';c <= 'z';c++) {
                        if(c == ori_c) continue;
                        curr_str[i] = c;
                        auto find_res = str_map.find(curr_str);
                        if(find_res != str_map.end()) {
                            if(find_res->second.d == 0) {
                                if(curr_str == endWord) found = true;
                                q.push(curr_str);
                                find_res->second.d = curr_d + 1;
                                find_res->second.from_strs.push_back(q.front());
                            }
                            else if(find_res->second.d == curr_d + 1) {
                                find_res->second.from_strs.push_back(q.front());
                            }
                        }
                    }
                    curr_str[i] = ori_c;
                }
                q.pop();
            }
            if(found) break;
        }
        if(!found) return {};
        else return dfs(endWord);
    }
private:
    unordered_map<string, Node> str_map;
    vector<vector<string>> dfs(const string& curr) {
        const Node& curr_node = str_map.find(curr)->second;
        if(curr_node.d == 2) return {{ curr_node.from_strs[0], curr }};
        vector<vector<string>> ret;
        for(const string& s : curr_node.from_strs) {
            vector<vector<string>> tmp_v = dfs(s);
            for(auto& v : tmp_v) v.push_back(curr);
            ret.insert(ret.end(), tmp_v.begin(), tmp_v.end());
        }
        return ret;
    }
};
