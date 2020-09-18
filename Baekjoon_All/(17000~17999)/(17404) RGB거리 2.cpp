#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1000001;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int cost[1001][4];
int dp[1001][4] = { 0, };

int main() {
	FASTIO;
	int N;
	int ans = INF;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, 3) {
			cin >> cost[i][j];
		}
	}

	dp[1][1] = cost[1][1];
	dp[1][2] = INF;
	dp[1][3] = INF;
	FOR(i, 2, N) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][3];
	}
	ans = min({ ans, dp[N][2], dp[N][3] });

	dp[1][1] = INF;
	dp[1][2] = cost[1][2];
	dp[1][3] = INF;
	FOR(i, 2, N) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][3];
	}
	ans = min({ ans, dp[N][1], dp[N][3] });

	dp[1][1] = INF;
	dp[1][2] = INF;
	dp[1][3] = cost[1][3];
	FOR(i, 2, N) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][3];
	}
	ans = min({ ans, dp[N][1], dp[N][2] });

	cout << ans;

	return 0;
}