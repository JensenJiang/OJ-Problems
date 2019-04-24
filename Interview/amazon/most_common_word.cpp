/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 819
 * Problem Title: Most Common Word
 * Keyword: string
 *
 */

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

inline bool is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_set;
        unordered_map<string,int> cnt_map;
        auto max_iter = cnt_map.end();
        for(const string& s : banned) banned_set.insert(s);

        for(int start = 0;start < paragraph.length();) {
            while(start < paragraph.length() && !is_letter(paragraph[start])) start++;

            int end = start;
            while(end < paragraph.length() && is_letter(paragraph[end])) end++;
            string curr_s = paragraph.substr(start, end - start);
            std::transform(curr_s.begin(), curr_s.end(), curr_s.begin(), ::tolower);
            auto find_banned = banned_set.find(curr_s);
            if(find_banned == banned_set.end()) {
                cnt_map[curr_s]++;
                if(max_iter == cnt_map.end() || cnt_map[curr_s] > max_iter->second) max_iter = cnt_map.find(curr_s);
            }
            start = end;
        }
        return max_iter->first;
    }
};
