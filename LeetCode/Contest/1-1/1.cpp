/* greedy algorithm or dp */

class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        unsigned int n2 = n;
        while(n2 > 1) {
            if(n2 & 1) {
                if((n2 & 2) && n2 != 3) {
                    n2++;
                }
                else n2--;
            }
            else {
                n2 >>= 1;
            }
            cnt++;
        }
        return cnt;
    }
};
