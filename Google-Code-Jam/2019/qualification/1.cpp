#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    int T;
    string input;

    cin >> T;
    getline(cin, input);
    for (int t = 1;t <= T;t++) {
        queue<char> q1, q2;

        getline(cin, input);
        for (const char c : input) {
            if (c == '4') {
                q1.push('2');
                q2.push('2');
            }
            else {
                q1.push(c);
                q2.push('0');
            }
        }
        
        while (!q2.empty() && q2.front() == '0') q2.pop();

        string s1, s2;
        while (!q1.empty()) {
            s1 += q1.front();
            q1.pop();
        }
        while (!q2.empty()) {
            s2 += q2.front();
            q2.pop();
        }
        if (s2.empty()) s2 += '0';

        cout << "Case #" << t << ": " << s1 << " " << s2 << endl;
    }
    return 0;
}
