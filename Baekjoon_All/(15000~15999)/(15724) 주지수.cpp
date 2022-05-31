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
	vector<vector<int>> v(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> v[i][j];
		}
	}

	FOR(i, 1, N) {
		FOR(j, 1, M) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v[i][j];
		}
	}

	int K;
	cin >> K;
	FOR(i, 1, K) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}

	return 0;
}