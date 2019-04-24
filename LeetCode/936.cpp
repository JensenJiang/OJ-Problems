/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 936
 * Problem Title: Stamp The Sequence
 * Keyword: string, dfs
 *
 */

#include <vector>
#include <string>
using std::vector;
using std::string;

inline bool ch_equal(char a, char b) {
    return a == '?' || b == '?' || a == b;
}

class KMPMatcher {
public:
    string pattern;
    int *bw;
    KMPMatcher(const string& p) {
        pattern = p;
        bw = new int[p.length() + 1];
        bw[0] = -1;
        for(int i = 0, j = bw[0];i < p.length();) {
            while(j >= 0 && p[i] != p[j]) j = bw[j];
            i++;
            j++;
            bw[i] = j;
        }
    }

    int search_first(const string& s) {
        for(int i = 0, j = 0;i < s.length();) {
            while(j >= 0 && !ch_equal(pattern[j], s[i])) j = bw[j];
            i++;
            j++;
            if(j == pattern.length()) {
                return i - j;
            }
        }
        return -1;
    }
};

class NaiveMatcher {
public:
    string pattern;
    NaiveMatcher(const string& p) {
        pattern = p;
    }
    int search_first(const string& s) {
        for(int i = 0;i <= s.length() - pattern.length();i++) {
            int j = i, k = 0;
            for(;k < pattern.length() && ch_equal(pattern[k], s[j]);j++, k++);
            if(k == pattern.length()) return i;
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        nm = new NaiveMatcher(stamp);
        p_len = stamp.length();
        if(dfs(target, 0, target.length() - 1, 0)) {
            return res;
        }
        else return {};
    }
    
    bool dfs(string curr_s, int val_s, int val_e, int d) {
        // printf("%s, [%d, %d]\n", curr_s.c_str(), val_s, val_e);
        int res_s = nm->search_first(curr_s);
        if(res_s == -1) return false;
        // printf("%d\n", res_s);
        curr_s.replace(res_s, p_len, p_len, '?');
        if(res_s > val_s) {
            if(!dfs(curr_s.substr(0, res_s + p_len - 1), val_s, res_s - 1, d)) return false;
        }
        if(res_s + p_len - 1 < val_e) {
            if(!dfs(curr_s.substr(res_s + 1, curr_s.length() - res_s - 1), p_len - 1, val_e - res_s - 1, d + res_s + 1)) return false;
        }
        res.push_back(res_s + d);
        return true;
    }
private:
    int p_len;
    vector<int> res;
    NaiveMatcher *nm;
};

int main() {
    Solution s;
    s.movesToStamp("abca", "aabcaca");
}
