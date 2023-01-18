#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<int> v(N + 1);
	vector<vector<int>> dp(N + 1, vector<int>(M + 2, INF));
	FOR(i, 1, N) {
		cin >> v[i];
	}
	dp[0][M + 1] = 0;
	FOR(i, 1, N) {
		if (dp[i - 1][M + 1] != INF) {
			dp[i][v[i]] = dp[i - 1][M + 1] + (M - v[i]) * (M - v[i]);
			dp[i][M + 1] = min(dp[i][M + 1], dp[i][v[i]]);
		}
		FOR(j, v[i] + 2, M) {
			int prev = j - 1 - v[i];
			if (dp[i - 1][prev] == INF) continue;
			dp[i][j] = dp[i - 1][prev] - (M - prev) * (M - prev) + (M - j) * (M - j);
			dp[i][M + 1] = min(dp[i][M + 1], dp[i][j]);
		}
	}

	int ans = INF;
	FOR(i, 1, M) {
		if (dp[N][i] == INF) continue;
		ans = min(ans, dp[N][i] - (M - i) * (M - i));
	}
	cout << ans;

	return 0;
}