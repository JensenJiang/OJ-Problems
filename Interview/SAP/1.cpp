#include <iostream>
#include <vector>

using namespace::std;

int solve(const string& curr_row, vector<int> last_res) {
    int tmp[2] = {last_res[0]};
    for (int i = 0; i < curr_row.length(); i++) {
        int place = curr_row[i] == '+' ? 0 : tmp[0] + 1;
        int nplace = max(tmp[0], tmp[1]);

        for (int j = 0; j < last_res.size(); j++) {
            last_res[j]
        }
    }
}

int main() {
    int R, C;
    string line;
    cin >> R >> C;
    getline(cin, line);  // Ignore linebreak
    for (int i = 0; i < R; i++) {
        getline(cin, line);
    }
}
