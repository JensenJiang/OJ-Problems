/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 12
 * Problem Title: Integer to Roman
 * Keyword: google
 *
 */

#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    Solution() {
        v_to_s[1] = 'I';
        v_to_s[5] = 'V';
        v_to_s[10] = 'X';
        v_to_s[50] = 'L';
        v_to_s[100] = 'C';
        v_to_s[500] = 'D';
        v_to_s[1000] = 'M';
        vals[0] = 1;
        vals[1] = 5;
        vals[2] = 10;
        vals[3] = 50;
        vals[4] = 100;
        vals[5] = 500;
        vals[6] = 1000;
    }
    string intToRoman(int num) {
        string ret = "";
        int k = 1000;
        int t = 6;
        while(k > 0) {
            int curr_d = num / k;
            if(curr_d > 0 && curr_d < 5) {
                if(curr_d == 4) {
                    ret.append(1, v_to_s[vals[t]]);
                    ret.append(1, v_to_s[vals[t+1]]);
                }
                else {
                    ret.append(curr_d, v_to_s[vals[t]]);
                }
            }
            else if(curr_d >= 5 && curr_d <= 9) {
                if(curr_d == 9) {
                    ret.append(1, v_to_s[vals[t]]);
                    ret.append(1, v_to_s[vals[t+2]]);
                }
                else {
                    ret.append(1, v_to_s[vals[t+1]]);
                    ret.append(curr_d - 5, v_to_s[vals[t]]);
                }
            }
            num = num % k;
            k = k / 10;
            t -= 2;
        }
        return ret;
    }
private:
    unordered_map<int, char> v_to_s;
    int vals[7];
};
