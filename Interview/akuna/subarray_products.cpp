#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;


int main() {
    int k;
    vector<int> nums;
    cin >> k;
    int tmp;
    while(cin >> tmp) {
        nums.push_back(tmp);
    }

    int product = 1,
        tot = 0;
    for(int i = 0, j = 0;i < nums.size();) {
        while(j < nums.size() && product * nums[j] <= k) {
            product *= nums[j];
            j++;
        }
        // cout << i << ',' << j << std::endl;
        tot += (j - i);
        i++;
        if(j < i) j = i;
        else product /= nums[i - 1];
    }
    
    cout << tot << std::endl;
    return 0;
}
