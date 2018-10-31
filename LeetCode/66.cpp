/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 66
 * Problem Title: Plus One
 * Keyword: google
 *
 */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size();
        digits[l-1] += 1;
        for(int i = l - 1;i >= 0 && digits[i] >= 10;i--) {
            digits[i] -= 10;
            if(i > 0) {
                digits[i-1] += 1;
            }
            else {
                digits.insert(digits.begin(), 1);
                break;
            }
        }
        return digits;
    }
};
