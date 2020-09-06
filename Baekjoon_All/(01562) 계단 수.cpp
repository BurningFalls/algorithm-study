#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000000
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll dp[101][10][1<<10] = { 0, };

int main() {
	FASTIO;
	int N;
	ll sum = 0;
	cin >> N;
	FOR(i, 1, 9)
		dp[1][i][1<<i] = 1;
	FOR(i, 2, N) {
		FOR(j, 0, 9) {
			FOR(k, 0, (1 << 10) - 1) {
				if (j == 0)
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % MOD;
				else if (j == 9)
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % MOD;
				else {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
				}
			}
		}
	}
	FOR(i, 0, 9)
		sum = (sum + dp[N][i][(1 << 10) - 1]) % MOD;

	cout << sum;

	return 0;
}