#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int C = 1 << 5;

int main() {
    int T;
    string input;

    cin >> T;
    for (int t = 1;t <= T;t++) {
        int N, B, F;
        cin >> N >> B >> F;
        getline(cin, input);

        vector<int> ids(N, 0);
        string res[5];
        for (int i = 0;i < N;i++) ids[i] = i % C;
        for (int i = 0;i < 5;i++) {
            string query;
            for (int j = 0;j < N;j++) {
                if (ids[j] & 1) query += '1';
                else query += '0';
                ids[j] >>= 1;
            }
            cout << query << endl;
            getline(cin, res[i]);
        }
        
        int exp_id = 0;
        int base = 0;
        vector<int> broken_ids;
        for (int i = 0;i < N - B;i++) {
            int curr_id = 0;
            for (int j = 4;j >= 0;j--) {
                curr_id <<= 1;
                if (res[j][i] == '1') curr_id += 1;
            }
            while (exp_id != curr_id) {
                broken_ids.push_back(exp_id + base);
                exp_id++;
                if (exp_id >= C) {
                    exp_id -= C;
                    base += C;
                }
            }
            exp_id++;
            if (exp_id >= C) {
                exp_id -= C;
                base += C;
            }
            if (broken_ids.size() >= B) break;
        }
        if (broken_ids.size() < B) {
            int size = broken_ids.size();
            for (int i = 0;i < B - size;i++) {
                broken_ids.push_back(exp_id + base);
                exp_id++;
                if (exp_id >= C) {
                    exp_id -= C;
                    base += C;
                }
            }
        }

        // Output
        cout << broken_ids.front();
        for (int i = 1;i < broken_ids.size();i++) {
            cout << " " << broken_ids[i];
        }
        cout << endl;

        getline(cin, input);
        if (input[0] != '1') break;
    }

    return 0;
}
