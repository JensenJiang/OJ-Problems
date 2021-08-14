/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 1007
 * Problem Title: Minimum Domino Rotations For Equal Row
 * Keyword: google
 *
 */

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans_1 = minRotationsGivenNum(A, B, A.front());
        if (ans_1 != -1) return ans_1;
        else if (A.front() != B.front()) return minRotationsGivenNum(A, B, B.front());
        else return -1;
    }
private:
    int minRotationsGivenNum(vector<int>& A, vector<int>& B, int num) {
        int rot_A = 0,
            rot_B = 0,
            tot_num = A.size();

        for (int i = 0;i < tot_num;i++) {
            if (num != A[i] && num != B[i]) return -1;
            if (num != A[i]) rot_A++;
            if (num != B[i]) rot_B++;
        }

        return min(rot_A, rot_B);
    }
};
