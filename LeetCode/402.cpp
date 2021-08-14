/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 402
 * Problem Title: Remove K Digits
 * Keyword: good, microsoft
 *
 */

#include <string>
#include <list>
using std::string;
using std::list;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.length()) return "0";

        list<char> num_list(num.begin(), num.end());
        auto ptr = num_list.begin();
        while (k) {
            auto num_list_last = std::prev(num_list.end(), 1);
            while (ptr != num_list_last) {
                auto next_ptr = std::next(ptr);
                if (*ptr > *next_ptr) break;
                ptr = next_ptr;
            }

            if (ptr == num_list_last) {
                num_list.erase(std::prev(num_list.end(), k), num_list.end());
                break;
            }
            else {
                ptr = std::prev(num_list.erase(ptr), 1);
                k--;
            }
        }

        // Remove leading 0s
        for (auto ptr = num_list.begin();ptr != num_list.end() && *ptr == '0';ptr = num_list.erase(ptr));

        if (num_list.empty()) return "0";
        
        return string(num_list.begin(), num_list.end());
    }
};
