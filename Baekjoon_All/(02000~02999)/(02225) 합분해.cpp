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
#define MOD 1000000000

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<vector<ll>> dp(K + 1, vector<ll>(N + 1));
	FOR(i, 0, N) {
		dp[1][i] = 1;
	}
	FOR(i, 1, K) {
		dp[i][0] = 1;
	}
	FOR(i, 2, K) {
		FOR(j, 1, N) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	cout << dp[K][N];

	return 0;
}