#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007

ll dp[2][9] = { 0, };

int main() {
	FASTIO;
	int D;
	cin >> D;
	dp[0][2] = 1;
	dp[0][3] = 1;
	FOR(i, 1, D - 1) {
		bool a, b;
		a = i % 2;
		b = !a;
		dp[a][1] = (dp[b][2] + dp[b][3]) % MOD;
		dp[a][2] = (dp[b][1] + dp[b][3] + dp[b][4]) % MOD;
		dp[a][3] = (dp[b][1] + dp[b][2] + dp[b][4] + dp[b][5]) % MOD;
		dp[a][4] = (dp[b][2] + dp[b][3] + dp[b][5] + dp[b][6]) % MOD;
		dp[a][5] = (dp[b][3] + dp[b][4] + dp[b][6] + dp[b][7]) % MOD;
		dp[a][6] = (dp[b][4] + dp[b][5] + dp[b][8]) % MOD;
		dp[a][7] = (dp[b][5] + dp[b][8]) % MOD;
		dp[a][8] = (dp[b][6] + dp[b][7]) % MOD;
	}
	cout << dp[(D - 1) % 2][1];

	return 0;
}