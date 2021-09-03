#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define MOD 9901

int N, M;
int dp[196][(1 << 14)];

int DP(int node, int state) {
	if (node == N * M) {
		if (state == 0)
			return 1;
		else
			return 0;
	}
	int& ret = dp[node][state];
	if (ret != -1)
		return ret;
	ret = 0;
	if (state & 1)
		ret = (ret + DP(node + 1, (state >> 1))) % MOD;
	else {
		ret = (ret + DP(node + 1, ((state >> 1) | (1 << (M - 1))))) % MOD;
		if ((!(state & 2)) && (node + 1) % M)
			ret = (ret + DP(node + 2, (state >> 2))) % MOD;
	}
	return ret;
}

int main() {
	FASTIO;
	MEMSET(dp, -1);
	cin >> N >> M;
	cout << DP(0, 0);

	return 0;
}