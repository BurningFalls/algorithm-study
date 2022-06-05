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
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<ll>> dp(M + 1, vector<ll>(N + 1, 0));
		FOR(i, 1, M) {
			dp[i][1] = i;
		}
		FOR(i, 1, M) {
			FOR(j, 2, N) {
				dp[i][j] = dp[i - 1][j];
				dp[i][j] += dp[i / 2][j - 1];
			}
		}
		cout << dp[M][N] << "\n";
	}

	return 0;
}