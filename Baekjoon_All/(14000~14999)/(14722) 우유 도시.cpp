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
	vector<vector<int>> v(N + 1, vector<int>(N + 1));
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(3, -INF)));
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> v[i][j];
			if (v[i][j] == 0) {
				dp[i][j][0] = 1;
			}
		}
	}

	FOR(i, 1, N) {
		FOR(j, 1, N) {
			FOR(k, 0, 2) {
				dp[i][j][k] = max({ dp[i][j][k], dp[i][j - 1][k], dp[i - 1][j][k] });
			}
			int cur = v[i][j];
			int prev = (cur + 2) % 3;
			dp[i][j][cur] = max({ dp[i][j][cur], dp[i][j - 1][prev] + 1, dp[i - 1][j][prev] + 1 });
		}
	}
	cout << max({ 0, dp[N][N][0], dp[N][N][1], dp[N][N][2] });

	return 0;
}