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
	int N;
	cin >> N;
	vector<vector<int>> Map(N + 1, vector<int>(N + 1));
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(10001, 0)));
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int maxi = 0;
			FOR(k, 1, 10000) {
				dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
				if (k < Map[i][j]) {
					maxi = max(maxi, dp[i][j][k]);
				}
			}
			dp[i][j][Map[i][j]] = max(dp[i][j][Map[i][j]], maxi + 1);
		}
	}

	int ans = 0;
	FOR(i, 1, 10000) {
		ans = max(ans, dp[N][N][i]);
	}
	cout << ans;

	return 0;
}