#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    int T;
    string input;

    cin >> T;
    for (int t = 1;t <= T;t++) {
        int P, Q;
        cin >> P >> Q;
        vector<int> cnt_x(Q+1, 0);
        vector<int> cnt_y(Q+1, 0);
        for (int i = 0;i < P;i++) {
            int x, y;
            char dir;
            cin >> x >> y >> dir;
            switch(dir) {
                case 'N':
                    for (int curr = y + 1;curr <= Q;curr++) {
                        cnt_y[curr]++;
                    }
                    break;
                case 'E':
                    for (int curr = x + 1;curr <= Q;curr++) {
                        cnt_x[curr]++;
                    }
                    break;
                case 'S':
                    for (int curr = y - 1;curr >= 0;curr--) {
                        cnt_y[curr]++;
                    }
                    break;
                case 'W':
                    for (int curr = x - 1;curr >= 0;curr--) {
                        cnt_x[curr]++;
                    }
                    break;
            }
        }
        int max_x = 0, max_y = 0;
        for (int i = 1;i <= Q;i++) {
            if (cnt_x[i] > cnt_x[max_x]) max_x = i;
        }
        for (int i = 1;i <= Q;i++) {
            if (cnt_y[i] > cnt_y[max_y]) max_y = i;
        }
        cout << "Case #" << t << ": " << " " << max_x << " " << max_y << endl;
    }
    return 0;
}
