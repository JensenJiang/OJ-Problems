/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 179
 * Problem Title: Largest Number
 * Keyword: string, good
 *
 */

#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::min;
using std::sort;

bool numstr_cmp(string const& a, string const& b) {
    int i = 0;
    // printf("%s %s\n", a.c_str(), b.c_str());
    for(;i < min(a.length(), b.length());i++) {
        if(a[i] == b[i]) continue;
        else {
            return a[i] < b[i];
        }
    }
    if(a.length() == b.length()) return false;
    else if(a.length() < b.length()) {
        int j = 0;
        for(;i < b.length();i++, j++) {
            if(b[i] == b[j]) continue;
            else {
                return b[j] < b[i];
            }
        }
        for(i = 0;i < a.length();i++, j++) {
            if(b[j] == a[i]) continue;
            else return b[j] < a[i];
        }
    }
    else {
        int j = 0;
        for(;i < a.length();i++, j++) {
            if(a[i] == a[j]) continue;
            else {
                return a[i] < a[j];
            }
        }
        for(i = 0;i < b.length();i++, j++) {
            if(b[i] == a[j]) continue;
            else return b[i] < a[j];
        }
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) return "0";
        vector<string> nums_str(nums.size());
        for(int i = 0;i < nums.size();i++) nums_str[i] = std::to_string(nums[i]);
        sort(nums_str.begin(), nums_str.end(), numstr_cmp);
        if(nums_str.back() == "0") return "0";
        string ret = "";
        for(auto i = nums_str.rbegin();i != nums_str.rend();i++) ret += *i;
        return ret;
    }    
};

int main() {
    Solution s;
    vector<int> in{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    s.largestNumber(in);
}
