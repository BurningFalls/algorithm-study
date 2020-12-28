#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
bool Map[33][33];
ll dp[33][33][3] = { 0, };

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N) {
		Map[0][i] = 1;
		Map[i][0] = 1;
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	dp[1][2][0] = 1;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (i == 1 && j == 1) continue;
			if (i == 1 && j == 2) continue;
			if (Map[i][j]) continue;
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
			if (Map[i][j - 1]) continue;
			if (Map[i - 1][j]) continue;
			dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
		}
	}
	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];

	return 0;
}