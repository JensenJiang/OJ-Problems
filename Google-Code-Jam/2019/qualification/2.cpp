#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    string input;

    cin >> T;
    getline(cin, input);
    for (int t = 1;t <= T;t++) {
        int N;

        cin >> N;
        getline(cin, input);
        getline(cin, input);
        
        string output;
        for (const char c : input) {
            if (c == 'E') output += 'S';
            else output += 'E';
        }

        cout << "Case #" << t << ": " << output << endl;
    }
    return 0;
}
