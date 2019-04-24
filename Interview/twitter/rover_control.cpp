#include <iostream>
#include <string>
using std::cin;
using std::string;
using std::cout;

int main() {
    int n, nr_c;
    int curr_x = 0, curr_y = 0;
    cin >> n;
    cin >> nr_c;

    string curr_c;
    while(nr_c--) {
        cin >> curr_c;
        if(curr_c == "LEFT" && curr_y > 0) {
            curr_y--;
        }
        else if(curr_c == "RIGHT" && curr_y < n - 1) {
            curr_y++;
        }
        else if(curr_c == "UP" && curr_x > 0) {
            curr_x--;
        }
        else if(curr_c == "DOWN" && curr_x < n - 1) {
            curr_x++;
        }
    }

    cout << curr_x * n + curr_y << std::endl;
    return 0;
}
