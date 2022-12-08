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
	vector<vector<int>> A(N + 1, vector<int>(M + 1));
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> A[i][j];
		}
	}
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	dp[1][1] = A[1][1];
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (i == 1 && j == 1) continue;
			if (x1 == x2 && i == x1 + 1 && min(y1, y2) < j && j <= max(y1, y2)) {
				if (dp[i][j - 1] == INF) {
					dp[i][j] = INF;
				}
				else {
					dp[i][j] = dp[i][j - 1] + A[i][j];
				}
			}
			else if (y1 == y2 && j == y1 + 1 && min(x1, x2) < i && i <= max(x1, x2)) {
				if (dp[i - 1][j] == INF) {
					dp[i][j] = INF;
				}
				else {
					dp[i][j] = dp[i - 1][j] + A[i][j];
				}
			}
			else if (dp[i][j - 1] == INF && dp[i - 1][j] == INF) {
				dp[i][j] = INF;
			}
			else if (dp[i][j - 1] == INF) {
				dp[i][j] = dp[i - 1][j] + A[i][j];
			}
			else if (dp[i - 1][j] == INF) {
				dp[i][j] = dp[i][j - 1] + A[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
			}
		}
	}
	
	if (dp[N][M] == INF) {
		cout << "Entity";
	}
	else {
		cout << dp[N][M];
	}

	return 0;
}