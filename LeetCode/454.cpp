/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 454
 * Problem Title: 4Sum II
 * Keyword: hash
 *
 */

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

typedef unordered_map<int, int> count_multiset;

inline void multiset_add(count_multiset &ms, int e) {
    auto iter = ms.find(e);
    if(iter != ms.end()) iter->second++;
    else ms[e] = 1;
}

inline int multiset_get(count_multiset &ms, int e) {
    auto iter = ms.find(e);
    if(iter != ms.end()) return iter->second;
    else return 0;
}

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int vec_size = A.size();
        if(vec_size == 0) return 0;
        
        count_multiset sums;
        for(auto const c : C) {
            for(auto const d : D) multiset_add(sums, c + d);
        }
        
        int res = 0;
        for(auto const a : A) {
            for(auto const b : B) {
                res += multiset_get(sums, -(a + b));
            }
        }
        return res;
    }
};
