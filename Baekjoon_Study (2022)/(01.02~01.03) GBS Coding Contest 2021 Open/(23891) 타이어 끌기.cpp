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
	int N, M;
	cin >> N >> M;
	vector<int> S(N + 1), P(N + 1);
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, -INF));
	FOR(i, 1, N) {
		cin >> S[i] >> P[i];
	}
	dp[0][0] = 0;
	FOR(i, 1, N) {
		ROF(j, M, 0) {
			if (j >= P[i] + 1 && dp[i - 1][j - (P[i] + 1)] != -INF) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - (P[i] + 1)] + S[i]);
			}
			if (j >= P[i] && dp[i - 1][j - P[i]] != -INF) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - P[i]]);
			}
			if (dp[i - 1][j] != -INF) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j] - S[i]);
			}
		}
	}
	int maxi = -INF;
	FOR(i, 0, M) {
		maxi = max(maxi, dp[N][i]);
	}
	if (maxi > 0) {
		cout << 'W';
	}
	else if (maxi == 0) {
		cout << 'D';
	}
	else if (maxi < 0) {
		cout << 'L';
	}

	return 0;
}