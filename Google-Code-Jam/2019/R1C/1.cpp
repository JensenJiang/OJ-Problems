#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> mapping = {{'R', 0}, {'S', 1}, {'P', 2}};
char back_mapping[3] = {'R', 'S', 'P'};
int win_mapping[3] = {1, 2, 0};
int lose_mapping[3] = {2, 0, 1};

int main() {
    int T;
    cin >> T;
    
    for (int t = 1;t <= T;t++) {
        int A,
            maxlen = 0;
        bool flag = true;
        string solution;
        cin >> A;
        vector<string> strarr(A);
        vector<bool> is_lose(A, false);
        int remain = A;
        cin.ignore();

        for (int i = 0;i < A;i++) {
            getline(cin, strarr[i]);
        }
        
        for (int i = 0;remain > 0;i++) {
            vector<int> ids[3];
            for (int j = 0;j < A;j++) {
                if (is_lose[j]) continue;
                int len = strarr[j].length();
                char action = strarr[j][i % len];
                ids[mapping[action]].push_back(j);
            }

            vector<int> not_empty;
            for (int j = 0;j < 3;j++) {
                if (!ids[j].empty()) not_empty.push_back(j);
            }
            int best_action = -1;
            if (not_empty.size() == 3) {
                flag = false;
                break;
            }
            else if (not_empty.size() == 1) {
                best_action = lose_mapping[not_empty[0]];
                solution += back_mapping[best_action];
            }
            else {
                if (not_empty[0] == 0) {
                    if (not_empty[1] == 1) {
                        solution += 'R';
                        best_action = 0;
                    }
                    else {
                        solution += 'P';
                        best_action = 2;
                    }
                }
                else {
                    solution += 'S';   
                    best_action = 1;
                }
            }
            for (int id : ids[win_mapping[best_action]]) {
                is_lose[id] = true;
            }
            remain -= ids[win_mapping[best_action]].size();
        }
        cout << "Case #" << t << ": ";
        if (flag) {
            cout << solution;
        }
        else {
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }
}
