/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 158
 * Problem Title: Read N Characters Given Read4 II - Call multiple times
 * Keyword: api, string, good, google
 *
 */

#include <cstring>
#include <algorithm>
using std::min;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    Solution() {
        lbuf_ptr = lbuf;
        lbuf_size = 0;
    }
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if(n == 0) return 0;
        int rest = n;
        char *curr_ptr = buf;
        if(lbuf_size > 0) {
            int inc = min(rest, lbuf_size);
            memcpy(curr_ptr, lbuf_ptr, inc);
            curr_ptr += inc;
            rest -= inc;
            lbuf_ptr += inc;
            lbuf_size -= inc;
            if(lbuf_size == 0) lbuf_ptr = lbuf;
        }
        while(rest > 0) {
            int c = read4(lbuf_ptr);
            int inc = min(c, rest);
            memcpy(curr_ptr, lbuf_ptr, inc);
            curr_ptr += inc;
            rest -= inc;
            if(inc < c) {
                lbuf_ptr += inc;
                lbuf_size = c - inc;
            }
            if(rest > 0 && c < 4) return n - rest;
        }
        return n;
    }
private:
    char lbuf[4];
    char *lbuf_ptr;
    int lbuf_size;
};
