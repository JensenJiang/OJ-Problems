#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

struct MyValue {
    int pos, value;
};

int count_pairs(const deque<MyValue>& dqc, const deque<MyValue>& dqd, int rl, int rr, int K) {
    int tot = 0,
        curr_l = 0;
    for (auto i = dqc.begin(), j = dqc.begin();i != dqc.end() && j != dqd.end();) {
        int delta = abs(i->value - j->value);
        if (delta <= K) {
            int min_l = min(i->pos, j->pos);
            if (min_l <= rl) {
                tot += (rr - rl + 1) * (min_l - curr_l + 1);
            }
            else if (curr_l <= rl) {
                tot += (min_l - rl + 1) * (rl - curr_l + 1) + (rr - min_l + 1) * (min_l - curr_l + 1);
            }
            else {

            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T;t++) {
        int N, K;
        cin >> N >> K;
        vector<int> carr(N, 0), darr(N, 0);
        deque<MyValue> dqc, dqd;
        for (int i = 0;i < N;i++) cin >> carr[i];
        for (int i = 0;i < N;i++) cin >> darr[i];
    }
    return 0;
}
