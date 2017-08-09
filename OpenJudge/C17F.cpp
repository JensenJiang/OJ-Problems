/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: C17F
 * Problem Title: A Simple Math Problem
 * Keyword:
 *
 */

#include <cstdio>
#include <cmath>
#define MOD 1000000007
typedef long long ll;
/* x^N mod 1,000,000,007 */

void muleq(ll res[2][2], ll t[2][2])
{
	ll sum[2][2];
	for(int i = 0;i < 2;i++) {
		for(int j = 0;j < 2;j++) {
			sum[i][j] = 0;
			for(int k = 0;k < 2;k++) {
				sum[i][j] += res[i][k] * t[k][j];
				sum[i][j] = (sum[i][j] + MOD) % MOD;
			}
		}
	}
	for(int i = 0;i < 2;i++)
		for(int j = 0;j < 2;j++)
			res[i][j] = sum[i][j];
}

int quick_power(int N)
{
	if(N == -1) return 1;
	ll x[2][2], res[2][2];
	x[0][0] = 14;
	x[0][1] = -1 + MOD;
	x[1][0] = 1;
	x[1][1] = 0;
	res[0][0] = res[1][1] = 1;
	res[0][1] = res[1][0] = 0;

	while(N) {
		if(N & 1) {
			muleq(res, x);
		}
		muleq(x, x);
		N >>= 1;
	}

	return (res[0][0] * 14 + res[0][1] * 2 - 1 + MOD) % MOD;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		printf("%d\n", quick_power(N-1));
	}
	return 0;
}
