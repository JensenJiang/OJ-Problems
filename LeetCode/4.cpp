/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 4
 * Problem Title: Median of Two Sorted Arrays
 * Keyword: binary_search, google
 *
 */

#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *nums_s, *nums_l;
        if(nums1.size() <= nums2.size()) {
            nums_s = &nums1;
            nums_l = &nums2;
        }
        else {
            nums_s = &nums2;
            nums_l = &nums1;
        }

        int size_s = nums_s->size(), size_l = nums_l->size();
        int size_tot = size_s + size_l;
        int m = (size_tot + 1) / 2;     // medium is the m-th number, not index!

        if(size_s == 0) {
            if(size_tot % 2 == 0) return (nums_l->at(m-1) + nums_l->at(m)) / 2.0;
            else return nums_l->at(m-1);
        }

        int l, r;
        for(l = 0, r = size_s;l < r;) {
            int i = (l + r) / 2;
            if(nums_l->at(m-1-i) > nums_s->at(i)) l = i + 1;
            else r = i;
        }
        
        int val_1, val_2;
        if(l >= size_s) {
            val_2 = nums_l->at(m - size_s);
            val_1 = m - size_s > 0 ? max(nums_s->at(size_s - 1), nums_l->at(m - size_s - 1)) : nums_s->at(size_s - 1);
        }
        else if (l == 0 or (l >= 1 && nums_s->at(l-1) <= nums_l->at(m-1-l))){
            val_1 = nums_l->at(m - 1 - l);
            val_2 = m - 1 - l < size_l - 1 ? min(nums_l->at(m-l), nums_s->at(l)) : nums_s->at(l);
        }
        else {
            val_1 = nums_s->at(l-1);
            val_2 = m - l < size_l ? min(nums_l->at(m-l), nums_s->at(l)) : nums_s->at(l);
        }

        if(size_tot % 2 == 0) {
            return (val_1 + val_2) / 2.0;
        }
        else return val_1;
    }
};
