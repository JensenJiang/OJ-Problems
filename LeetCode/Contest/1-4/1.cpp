/* use only two queue two implement the same idea */

#include <string>
#include <queue>
using std::string;
using std::queue;
using std::min;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int curr_bit = 0;
        for(int i = 0;i < senate.length();i++) {
            if(senate[i] == 'R') q[0][0].push(i);
            else q[1][0].push(i);
        }

        while(!q[0][curr_bit].empty() && !q[1][curr_bit].empty()) {
            int size_0 = q[0][curr_bit].size(), size_1 = q[1][curr_bit].size();
            for(int i = 0;i < min(size_0, size_1);i++) {
                int curr_0 = q[0][curr_bit].front(), curr_1 = q[1][curr_bit].front();
                q[0][curr_bit].pop();
                q[1][curr_bit].pop();
                if(curr_0 < curr_1) q[0][curr_bit ^ 1].push(curr_0);
                else q[1][curr_bit ^ 1].push(curr_1);
            }
            if(size_0 != size_1) {
                int more_i = size_0 > size_1 ? 0 : 1;
                int rest_size = q[more_i][curr_bit].size();
                for(int i = 0;i < rest_size;i++) {
                    q[more_i][curr_bit ^ 1].push(q[more_i][curr_bit].front());
                    q[more_i][curr_bit].pop();
                    if(!q[more_i ^ 1][curr_bit ^ 1].empty()) q[more_i ^ 1][curr_bit ^ 1].pop();
                    else break;
                }
            }
            curr_bit ^= 1;
        }

        if(q[0][curr_bit].empty()) return "Dire";
        else return "Radiant";
    }
private:
    queue<int> q[2][2];
};
