/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 734
 * Problem Title: Sentence Similarity
 * Keyword:
 *
 */

// A better solution: use set instead of vector to store words

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        unordered_map<string, vector<string>> similar_words;
        for (const vector<string>& pair : pairs) {
            similar_words[pair[0]].push_back(pair[1]);
            similar_words[pair[1]].push_back(pair[0]);
        }

        if (words1.size() != words2.size()) return false;
        
        for (int i = 0;i < words1.size();i++) {
            if (words1[i] == words2[i]) continue;
            bool is_similar = false;
            for (const string& similar_word : similar_words[words1[i]]) {
                if (similar_word == words2[i]) {
                    is_similar = true;
                    break;
                }
            }
            if (!is_similar) return false;
        }
        return true;
    }
};
