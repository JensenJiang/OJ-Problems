/*
 * Author: Jensen Jiang<jensenjiang1995@gmail.com>
 * Problem ID: 1029
 * Problem Title: Ministry
 * Keyword: DP
 *
 */

#include <cstdio>
#include <limits>
#include <algorithm>
#include <stack>

#define MAXM 102
#define MAXN 502
using namespace std;

struct DPINFO{
	long long dp[3];	// 0: left, 1: right, 2: down
	long long cost;
	int delta;

	long long get_min(){
		long long ret = dp[2];
		int index = 2;
		for(int i = 0;i < 2;i++)
			if(dp[i] < ret){
				ret = dp[i];
				index = i;
			}
		if(index == 0) delta = -1;
		else if(index == 1) delta = 1;
		else delta = 0;
		return (ret + cost);
	}
};

int M, N;
DPINFO info[MAXM][MAXN];

int solve(){
	long long INFTY = numeric_limits<long long>::max();
	for(int j = 1;j <= N;j++) info[2][j].dp[2] = info[1][j].cost;

	for(int i = 2;i <= M - 1;i++){
		info[i][1].dp[0] = info[i][N].dp[1] = INFTY;

		/* left-to-right scan */
		for(int j = 2;j <= N;j++) info[i][j].dp[0] = min(info[i][j-1].dp[0], info[i][j-1].dp[2]) + info[i][j-1].cost;

		/* right-to-left scan */
		for(int j = N - 1;j >= 1;j--) info[i][j].dp[1] = min(info[i][j+1].dp[1], info[i][j+1].dp[2]) + info[i][j+1].cost;
		for(int j = 1;j <= N;j++) info[i+1][j].dp[2] = info[i][j].get_min();
	}
	int index = 1;
	long long _min = info[M][1].dp[2] + info[M][1].cost;
	for(int j = 2;j <= N;j++)
		if(info[M][j].dp[2] + info[M][j].cost < _min){
			_min = info[M][j].dp[2] + info[M][j].cost;
			index = j;
		}
	return index;
}

void print_path(int end){
	stack<int> path;
	path.push(end);
	int cur_s = end;
	for(int cur_l = M;cur_l > 1;){
		int d = info[cur_l][cur_s].delta;
		if(d == 0) cur_l--;
		cur_s += d;
		path.push(cur_s);
	}

	printf("%d", path.top());
	path.pop();
	while(!path.empty()){
		printf(" %d", path.top());
		path.pop();
	}
	printf("\n");
}

int main()
{
	scanf("%d%d", &M, &N);
	for(int i = 1;i <= M;i++)
		for(int j = 1;j <= N;j++)
			scanf("%lld", &info[i][j].cost);
	print_path(solve());
	return 0;
}
