/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 151
 * Problem Title: Reverse Words in a String
 * Keyword: string, good
 *
 */

/* better solution: first reverse the string, then reverse every word and construct the specific format */

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    void reverseWords(string &s) {
        int start = 0,
            end = 0;
        vector<string> str_arr;
        while(end < s.length()) {
            if(s[end] == ' ') {
                if(end - start > 0) {
                    str_arr.push_back(s.substr(start, end - start));
                }
                start = end = end + 1;
            }
            else end++;
        }
        if(end - start > 0) {
            str_arr.push_back(s.substr(start, end - start));
        }

        s = str_arr.empty() ? "" : str_arr.back();
        for(int i = str_arr.size() - 2;i >= 0;i--) {
            s += (" " + str_arr[i]);
        }
    }
};
