#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1;t <= T;t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> combs(N);
        for (int i = 0;i < N;i++) {
            cin >> combs[i].first >> combs[i].second;
        }

        vector<double> vals;
        for (int i = 0;i < N;i++) {
            for (int j = i + 1;j < N;j++) {
                if ((combs[i].first > combs[j].first && combs[i].second < combs[j].second) || (combs[i].first < combs[j].first && combs[i].second > combs[j].second)) {
                    vals.push_back(double(combs[i].first - combs[j].first) / (combs[j].second - combs[i].second));
                }
            }
        }

        sort(vals.begin(), vals.end());
        auto last = unique(vals.begin(), vals.end(), [](double l, double r) {return std::abs(l - r) < 1e-10; });
        int num = distance(vals.begin(), last) + 1;
        cout << "Case #" << t << ": " << num <<endl;
    }
}
