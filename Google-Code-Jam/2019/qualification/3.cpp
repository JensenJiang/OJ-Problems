#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

class primeGen {
public:
    vector<int> primes;
    int upper;
    primeGen(int u) : upper(u) {
        vector<bool> is_prime(u, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2;i <= sqrt(u) + 1;i++) {
            if (is_prime[i]) primes.push_back(i);
            for (int j = i + i;j <= u;j += i) {
                is_prime[j] = false;
            }
        }
        for (int i = sqrt(u) + 2;i <= u;i++) {
            if (is_prime[i]) primes.push_back(i);
        }
    }
    pair<int, int> factor(int p) {
        for (const int f : primes) {
            if (p % f == 0) return {f, p / f};
        }
    }
};

int main() {
    int T;
    string input;

    cin >> T;
    for (int t = 1;t <= T;t++) {
        int N, L;
        cin >> N >> L;
        getline(cin, input);
        getline(cin, input);
        primeGen pg(N);
        istringstream num_stream(input);
        vector<int> products(L);
        vector<int> nums(L+1);
        for (int i = 0;i < L;i++) num_stream >> products[i];
        
        int known_pos = -1;
        for (int i = 0;i < L - 1;i++) {
            if (products[i] != products[i+1]) {
                auto f1 = pg.factor(products[i]);
                auto f2 = pg.factor(products[i+1]);
                // cout << f1.first << "," << f1.second << endl;
                // cout << f2.first << "," << f2.second << endl;
                if (f1.first == f2.first || f1.first == f2.second) {
                    nums[i+1] = f1.first;
                }
                else nums[i+1] = f1.second;
                known_pos = i + 1;
                break;
            }
        }

        for (int i = known_pos - 1;i >= 0;i--) {
            nums[i] = products[i] / nums[i+1];
        }
        for (int i = known_pos + 1;i <= L;i++) {
            nums[i] = products[i-1] / nums[i-1];
        }

        map<int, char> decrypt;
        for (const int a : nums) {
            decrypt[a] = 0;
        }
        char curr_c = 'A';
        for (auto i = decrypt.begin();i != decrypt.end();i++) {
            i->second = curr_c;
            curr_c++;
        }

        string output;
        for (const int a : nums) output += decrypt[a];
        
        cout << "Case #" << t << ": " << output << endl;
    }

    return 0;
}
