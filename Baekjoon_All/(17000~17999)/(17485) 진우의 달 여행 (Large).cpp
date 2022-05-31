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
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N + 2, vector<int>(M + 2));
	vector<vector<vector<int>>> dp(N + 2, vector<vector<int>>(M + 2, vector<int>(3, INF)));
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> v[i][j];
		}
	}

	FOR(i, 1, M) {
		FOR(j, 0, 2) {
			dp[0][i][j] = 0;
		}
	}

	FOR(i, 1, N) {
		FOR(j, 1, M) {
			dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + v[i][j];
			dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + v[i][j];
			dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + v[i][j];
		}
	}

	int mini = INF;
	FOR(i, 1, M) {
		FOR(j, 0, 2) {
			mini = min(mini, dp[N][i][j]);
		}
	}
	cout << mini;

	return 0;
}