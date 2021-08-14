/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 737
 * Problem Title: Sentence Similarity II
 * Keyword: union-find-set
 *
 */

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class UnionFindSet {
public:
    int nr_nodes;
    vector<int> par;
    vector<int> size;

    UnionFindSet(const int n): nr_nodes(n) {
        par.resize(n);
        size.resize(n);      // After union opreation, only the root parent's value is valid
        for(int i = 0;i < n;i++) {
            par[i] = i;
            size[i] = 1;        // Default size as 1, can be overrided after init
        }
    }

    int find(const int cur) {
        if(cur == par[cur]) return cur;
        else return par[cur] = find(par[cur]);
    }

    void union_nodes(const int a, const int b) {
        int par_a = find(a), par_b = find(b);
        if(par_a == par_b) return;
        if(size[par_a] >= size[par_b]) {
            par[par_b] = par_a;
            size[par_a] += size[par_b];
        }
        else {
            par[par_a] = par_b;
            size[par_b] += size[par_a];
        }
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;

        unordered_map<string,int> word2id;
        UnionFindSet ufs(pairs.size() * 2);
        
        for (const vector<string>& pair : pairs) {
            int id1, id2;
            const auto iter1 = word2id.find(pair[0]);
            if (iter1 == word2id.end()) {
                id1 = word2id.size();
                word2id[pair[0]] = id1;
            }
            else {
                id1 = iter1->second;
            }

            const auto iter2 = word2id.find(pair[1]);
            if (iter2 == word2id.end()) {
                id2 = word2id.size();
                word2id[pair[1]] = id2;
            }
            else {
                id2 = iter2->second;
            }

            ufs.union_nodes(id1, id2);
        }

        for (int i = 0;i < words1.size();i++) {
            int id1, id2;
            const auto iter1 = word2id.find(words1[i]);
            const auto iter2 = word2id.find(words2[i]);
            if (iter1 == word2id.end()) {
                id1 = -1;
            }
            else {
                id1 = iter1->second;
            }
            if (iter2 == word2id.end()) {
                id2 = -1;
            }
            else {
                id2 = iter2->second;
            }
            if (id1 >= 0 && id2 >= 0) {
                int par1 = ufs.find(id1),
                    par2 = ufs.find(id2);
                if (par1 == par2) continue;
                else return false;
            }
            else {
                if (words1[i] == words2[i]) continue;
                else return false;
            }
        }
        return true;
    }
};
