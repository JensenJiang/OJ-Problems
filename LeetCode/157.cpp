/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 157
 * Problem Title: Read N Characters Given Read4
 * Keyword: api, string
 *
 */

#include <cstring>
#include <algorithm>
using std::min;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int rest = n;
        char ch_buff[4];
        char *curr_ptr = buf;
        while(rest > 0) {
            int c = read4(ch_buff);
            int inc = min(c, rest);
            strncpy(curr_ptr, ch_buff, inc);
            curr_ptr += inc;
            rest -= inc;
            if(c < 4) return n - rest;
        }
        return n;
    }
};
