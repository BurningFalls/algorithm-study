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
	int N;
	cin >> N;
	vector<vector<int>> Map(N + 1, vector<int>(N + 1));
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(2, 0)));
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int a = dp[i - 1][j][0];
			int b = dp[i][j - 1][0];
			int c = dp[i - 1][j][1];
			int d = dp[i][j - 1][1];
			dp[i][j][0] = max(a, b) + Map[i][j];
			dp[i][j][1] = max(max(c, d) + Map[i][j], max(a, b) + Map[i][j] * 2);
		}
	}
	cout << max(dp[N][N][0], dp[N][N][1]);

	return 0;
}