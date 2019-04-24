#include <vector>
#include <string>
using std::vector;
using std::string;

bool case_insen_eq(char a, char b) {
    if(a >= 'A' && a <= 'Z') a = a - 'A' + 'a';
    if(b >= 'A' && b <= 'Z') b = b - 'A' + 'a';
    return a == b;
}

bool is_vowel(char a) {
    if(a >= 'A' && a <= 'Z') a = a - 'A' + 'a';
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
    else return false;
}

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        for(string q : queries) {
            int index_arr[3] = {-1, -1, -1};
            for(unsigned int i = 0;i < wordlist.size();i++) {
                if(q.length() != wordlist[i].length()) continue;
                bool match_arr[3] = {true, true, true};
                string &curr_w = wordlist[i];
                for(unsigned int j = 0;j < q.length();j++) {
                    if(q[j] != curr_w[j]) {
                        match_arr[0] = false;
                        if(!case_insen_eq(q[j], curr_w[j])) {
                            match_arr[1] = false;
                            if(!(is_vowel(q[j]) && is_vowel(curr_w[j]))) {
                                match_arr[2] = false;
                                break;
                            }
                        }
                    }
                } 
                for(unsigned int k = 0;k < 3;k++) {
                    if(match_arr[k] && index_arr[k] < 0) index_arr[k] = i;
                }
                if(match_arr[0]) break;
            }
            bool has_match = false;
            for(unsigned int k = 0;k < 3;k++) {
                if(index_arr[k] >= 0) {
                    ans.push_back(wordlist[index_arr[k]]);
                    has_match = true;
                    break;
                }
            }
            if(!has_match) ans.push_back("");
        }
        return ans;
    }
};
