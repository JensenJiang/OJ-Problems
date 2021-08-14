/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 88
 * Problem Title: Merge Sorted Array
 * Keyword: sort, good
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iter1 = m - 1,
            iter2 = n - 1,
            iter = m + n - 1;
        while (iter1 >= 0 || iter2 >= 0) {
            if (iter1 < 0) {
                nums1[iter--] = nums2[iter2--];
            }
            else if (iter2 < 0) {
                nums1[iter--] = nums1[iter1--];
            }
            else {
                if (nums1[iter1] >= nums2[iter2]) {
                    nums1[iter--] = nums1[iter1--];
                }
                else {
                    nums1[iter--] = nums2[iter2--];
                }
            }
        }
        return;
    }
};
