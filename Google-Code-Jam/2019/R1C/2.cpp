#include <iostream>
#include <vector>
#include <string>

using namespace std;

int qnums[4] = {119, 23, 5, 1};

int main() {
    int T, F;
    string input;

    cin >> T >> F;
    cin.ignore();
    for (int t = 1;t <= T;t++) {
        vector<int> ids[5];
        vector<int> all_base_ids(119, 0);
        vector<char> ans(5, 'T');
        for (int i = 0;i < 119;i++) all_base_ids[i] = i;
        int last_win = 0;

        for (int i = 0;i < 4;i++) {
            vector<int> base_ids = (i == 0) ? all_base_ids : ids[last_win];
            for (int j = 0;j < 5;j++) ids[j].clear();
            for (int base_id : base_ids) {
                int idx = base_id * 5 + i + 1;
                cout << idx << endl;
                getline(cin, input);
                ids[input[0] - 'A'].push_back(base_id);
            }

            if (i != 3) {
                for (int j = 0;j < 5;j++) {
                    if (ids[j].size() == qnums[i+1]) {
                        last_win = j;
                        ans[i] = 'A' + j;
                        break;
                    }
                }
            }
            else {
                ans[4] = input[0];
            }
        }
        vector<bool> flag(5, false);
        for (int i = 0;i < 5;i++) {
            if (i != 3) {
                flag[ans[i] - 'A'] = true;
            }
        }
        for (int i = 0;i < 5;i++) {
            if (!flag[i]) {
                ans[3] = i + 'A';
                break;
            }
        }
        for (int i = 0;i < 5;i++) {
            cout << ans[i];
        }
        cout << endl;
        getline(cin, input);
        if (input[0] == 'N') break;
    }
}
