#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MOD 1000000007

ll dp[1001][1001] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	dp[1][1] = 1;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (i == 1 && j == 1) continue;
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	cout << dp[N][M];

	return 0;
}