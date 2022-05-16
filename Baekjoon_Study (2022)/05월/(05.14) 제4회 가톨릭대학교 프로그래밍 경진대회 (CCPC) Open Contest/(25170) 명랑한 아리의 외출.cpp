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

int main() {
	FASTIO;
	int N, M, T;
	cin >> N >> M >> T;
	vector<vector<pii>> Map(N + 1, vector<pii>(M + 1));
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(T + 1, -1)));
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j].first;
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j].second;
		}
	}

	dp[1][1][0] = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (i == 1 && j == 1) continue;
			FOR(t, 1, T) {
				int a = dp[i][j - 1][t - 1];
				int b = dp[i - 1][j][t - 1];
				int c = dp[i - 1][j - 1][t - 1];
				int tmp = t - 1 - Map[i][j].second;
				int d = (tmp >= 0 && dp[i][j - 1][tmp] != -1 ? dp[i][j - 1][tmp] + Map[i][j].first : -1);
				int e = (tmp >= 0 && dp[i - 1][j][tmp] != -1 ? dp[i - 1][j][tmp] + Map[i][j].first : -1);
				int f = (tmp >= 0 && dp[i - 1][j - 1][tmp] != -1 ? dp[i - 1][j - 1][tmp] + Map[i][j].first : -1);
				dp[i][j][t] = max({ a, b, c, d, e, f });
			}
		}
	}

	int maxi = 0;
	FOR(t, 0, T) {
		maxi = max(maxi, dp[N][M][t]);
	}
	cout << maxi;

	return 0;
}