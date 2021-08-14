/* https://leetcode.com/discuss/interview-question/356449 */

#include <vector>
#include <iostream>
using namespace std;

int watering_plants(vector<int> plants, int capacity) {
    int curr_cap = capacity,
        tot_steps = 0;

    for (int i = 0;i < plants.size();i++) {
        tot_steps++;
        if (plants[i] > curr_cap) {
            tot_steps += i * 2;
            curr_cap = capacity;
        }
        curr_cap -= plants[i];
    }

    return tot_steps;
}

int main() {
    cout << watering_plants({2, 4, 5, 1, 2}, 6) << endl;
    cout << watering_plants({}, 10) << endl;
    cout << watering_plants({1, 1, 2}, 3) << endl;
}
