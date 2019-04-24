/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 686
 * Problem Title: Repeated String Match
 * Keyword: google, string
 *
 */

#include <string>
using std::string;

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

    int ring_search_first(const string& s) {
        int nr_rep = 1;
        for(int i = 0, j = 0;i < s.length();) {
            while(j >= 0 && pattern[j] != s[i]) j = bw[j];
            i++;
            j++;
            if(j == pattern.length()) {
                return nr_rep;
            }
            if(i == s.length()) {
                i = 0;
                nr_rep += 1;
            }
            printf("%d %d %d\n", i, j, nr_rep);
            if(nr_rep > 1 && ((nr_rep - 2) * s.length() + i >= j)) return -1;
        }
        return -1;
    }
};

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        KMPMatcher kmp(B);
        return kmp.ring_search_first(A);
    }
};

int main() {
    Solution a;
    a.repeatedStringMatch("abcd", "cdabcdab");
}
