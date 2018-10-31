/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 388
 * Problem Title: Longest Absolute File Path
 * Keyword: google, string, simulation
 *
 */

#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::max;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> cl_arr;
        int max_len = 0;
        int i = 0;
        while(true) {
            bool is_file = false;
            int cur_level, j;
            for(j = i;j < input.length() && input[j] == '\t';j += 1);
            cur_level = j - i;
            i = j;

            for(j = i;j < input.length() && input[j] != '\n';j++) if(input[j] == '.') is_file = true;
            if(cl_arr.size() < cur_level + 1) cl_arr.push_back(0);
            if(cur_level == 0) cl_arr[cur_level] = j - i;
            else cl_arr[cur_level] = cl_arr[cur_level-1] + j - i + 1;
            i = j;

            if(is_file) max_len = max(max_len, cl_arr[cur_level]);
            
            if(i == input.length()) break;
            else i+=1;
        }
        return max_len;
    }
};
