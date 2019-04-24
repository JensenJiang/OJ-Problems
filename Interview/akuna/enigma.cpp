#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
using std::cin;
using std::cout;
using std::vector;

class Primes {
public:
vector<bool> is_prime;
vector<vector<int>> prime_factors;
    Primes(int r_max) {
        is_prime.resize(r_max + 1, true);
        prime_factors.resize(r_max + 1);
        is_prime[1] = false;

        for(int i = 2;i <= r_max;i++) {
            if(is_prime[i]) {
                prime_factors[i].push_back(i);
                for(int j = i + i;j <= r_max;j += i) {
                    is_prime[j] = false;
                    prime_factors[j].push_back(i);
                }
            }
        }
    }

    int find_nr_coprimes(int num, int r_min, int r_max) {
        int cnt = 0;
        vector<int> info_v;
        info_v.reserve(int(pow(2, prime_factors[num].size())));
        info_v.push_back(-1);
        for(int pf : prime_factors[num]) {
            int size = info_v.size();
            for(int i = 0;i < size;i++) {
                int curr_f = info_v[i] * pf * (-1);
                int abs_f = abs(curr_f);
                int sign = curr_f >= 0 ? 1 : -1;
                cnt += sign * ((r_max / abs_f) - ((r_min - 1) / abs_f));
                
                info_v.push_back(curr_f);
            }
        }
        return (r_max - r_min + 1) - cnt;
    }
};

long long quick_pow(int num, int p) {
    long long tmp = num % MOD,
              res = 1;
    while(p > 0) {
        if(p & 1) {
            res = res * tmp % MOD;
        }
        tmp = tmp * tmp % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    int nr_r, r_min, r_max;
    cin >> nr_r >> r_min >> r_max;
    Primes primes(r_max);
    long long ans = 0;
    for(int i = r_min;i <= r_max;i++) {
        int nr_coprimes = primes.find_nr_coprimes(i, r_min, r_max);
        cout << nr_coprimes << std::endl;
        ans += quick_pow(nr_coprimes, nr_r - 1);
        ans %= MOD;
    }
    cout << ans << std::endl;

    return 0;
}
