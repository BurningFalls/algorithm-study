#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MOD 1000000007

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<ll>> Map(N + 1, vector<ll>(M + 2, 0));
	vector<vector<ll>> dp(N + 1, vector<ll>(M + 2, 0));
	FOR(i, 1, N ) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, M) {
		dp[N][i] = Map[N][i];
	}
	ROF(i, N - 1, 1) {
		FOR(j, 1, M) {
			if (Map[i][j] == 0) continue;
			dp[i][j] = (dp[i + 1][j - 1] + dp[i + 1][j] + dp[i + 1][j + 1]) % MOD;
		}
	}
	ll ans = 0;
	FOR(i, 1, M) {
		ans = (ans + dp[1][i]) % MOD;
	}
	cout << ans;

	return 0;
}