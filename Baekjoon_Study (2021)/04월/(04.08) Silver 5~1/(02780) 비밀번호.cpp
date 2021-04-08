#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1234567

int dp[1001][10] = { 0, };
int sum[1001] = { 0, };

int main() {
	FASTIO;
	FOR(i, 0, 9)
		dp[1][i] = 1;
	FOR(i, 2, 1000) {
		dp[i][0] = dp[i - 1][7];
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % MOD;
		dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % MOD;
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
		dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % MOD;
		dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % MOD;
		dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % MOD;
		dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % MOD;
		dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % MOD;
	}
	FOR(i, 1, 1000) {
		FOR(j, 0, 9) {
			sum[i] = (sum[i] + dp[i][j]) % MOD;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << sum[N] << "\n";
	}


	return 0;
}