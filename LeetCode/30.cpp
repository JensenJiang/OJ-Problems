/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 30
 * Problem Title: Substring with Concatenation of All Words
 * Keyword: string, hard, good
 *
 */

#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        unordered_map<string, int> p_cnt;
        vector<int> ans;
        for(const string& p : words) {
            auto find_res = p_cnt.find(p);
            if(find_res == p_cnt.end()) {
                p_cnt[p] = 1;
            }
            else {
                find_res->second++;
            }
        }

        int p_len = words[0].length();
        for(int i = 0;i < p_len;i++) {
            int start = i,
                end = i,
                matched = 0;
            unordered_map<string, int> curr_cnt = p_cnt;
            while(start + words.size() * p_len - 1 < s.length()) {
                while(matched < words.size() && end + p_len - 1 < s.length()) {
                    string curr_word = s.substr(end, p_len);
                    auto find_res = curr_cnt.find(curr_word);
                    if(find_res == curr_cnt.end()) {
                        start = end + p_len;
                        end = start;
                        matched = 0;
                        curr_cnt = p_cnt;
                    }
                    else {
                        if(find_res->second > 0) {
                            find_res->second--;
                            matched++;
                            end += p_len;
                        }
                        else {
                            while(start < end) {
                                string re_word = s.substr(start, p_len);
                                curr_cnt[re_word]++;
                                matched--;
                                start += p_len;
                                if(find_res->second > 0) break;
                            }
                        }
                    }
                }
                if(matched == words.size()) {
                    ans.push_back(start);
                    string re_word = s.substr(start, p_len);
                    curr_cnt[re_word]++;
                    start += p_len;
                    matched--;
                }
                else break;
            }
        }
        return ans;
    }
};
