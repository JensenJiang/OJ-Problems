/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 1
 * Problem Title: Two Sum
 * Keyword:
 *
 */

#include <vector>
#include <algorithm>
#include <cstdio>
using std::vector;
using std::lower_bound;

struct my_pair {
    int num, id;
    bool operator <(const my_pair& a) const {
        return num < a.num;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nr_nums = nums.size();
        vector<my_pair> pairs_arr;
        for(int i = 0;i < nr_nums;i++) {
            pairs_arr.push_back({nums[i], i});
        }

        sort(pairs_arr.begin(), pairs_arr.end());
        for(auto i = pairs_arr.begin();i != pairs_arr.end();i++) {
            int t = target - i->num;
            auto j = lower_bound(i+1, pairs_arr.end(), (my_pair) {t, -1});
            if(j->num == t) {
                vector<int> result{i->id, j->id};
                return result;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    vector<int> r = s.twoSum(nums, 9);
    for(auto i = r.begin();i != r.end();i++) {
        printf("%d\n", *i);
    }
    return 0;
}
