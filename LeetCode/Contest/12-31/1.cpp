#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

struct range {
    int l, r;
    bool operator <(const range& a) const {
        return l < a.l;
    }
};

class Solution {
public:
    int bestRotation(vector<int>& A) {
        vector<range> range_arr;
        int N = A.size();
        for(int i = 0;i < A.size();i++) {
            if(A[i] + 1 <= N) range_arr.push_back({i + 1, i + N - A[i]});
            if(A[i] <= i) range_arr.push_back({0, i - A[i]});
        }

        sort(range_arr.begin(), range_arr.end());
        
        int max_v = 0,
            max_k = -1;
        priority_queue<int, vector<int>, std::greater<int> > ends;

        for(const range& ra : range_arr) {
            while(!ends.empty() && ra.l > ends.top()) ends.pop();
            ends.push(ra.r);
            if(ends.size() > max_v) {
                max_v = ends.size();
                max_k = ra.l;
            }
        }
        return max_k;
    }
};

