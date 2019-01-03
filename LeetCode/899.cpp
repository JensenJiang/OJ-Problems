/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 899
 * Problem Title: Orderly Queue
 * Keyword: math
 *
 */

#include <string>
using std::string;
using std::sort;

bool is_leq(const string& circle_S, int i, int j) {
    int len = circle_S.length();
    for(int k = 0;k < len;k++) {
        if(circle_S[(i + k) % len] < circle_S[(j + k) % len]) return true;
        else if(circle_S[(i + k) % len] > circle_S[(j + k) % len]) return false;
    }
    return true;
}

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        else {
            int min_i = 0;
            for(int i = 1;i < S.size();i++) {
                if(!is_leq(S, min_i, i)) min_i = i;
            }
            return S.substr(min_i, S.length() - min_i) + S.substr(0, min_i);
        }
    }
};
