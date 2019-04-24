/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 658
 * Problem Title: Find K Closest Elements
 * Keyword: binary_search, good
 *
 */

/* Better solution: find the left interval using binary search */

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto l = std::lower_bound(arr.begin(),arr.end(), x);
        auto r = l;
        
        while(k > 0) {
            if(r == arr.end()) l--;
            else if(l == arr.begin()) r++;
            else {
                if(x - *(l - 1) <= *r - x) l--;
                else r++;
            }
            k--;
        }

        return vector<int>(l, r);
    }
};
