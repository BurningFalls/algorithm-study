#include <bits/stdc++.h>
using namespace std;

#define INF 4000001
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int r[201], g[201], b[201];
int dp[201][201][201];

int main() {
	FASTIO;
	int R, G, B;
	int ans = 0;
	memset(dp, -INF, sizeof(dp));
	cin >> R >> G >> B;
	FOR(i, 1, R) cin >> r[i];
	FOR(i, 1, G) cin >> g[i];
	FOR(i, 1, B) cin >> b[i];
	sort(r + 1, r + R + 1, greater<int>());
	sort(g + 1, g + G + 1, greater<int>());
	sort(b + 1, b + B + 1, greater<int>());
	dp[0][0][0] = 0;
	FOR(i, 0, R) FOR(j, 0, G) FOR(k, 0, B) {
		if (i == 0 && j == 0 && k == 0) continue;
		int temp1 = -1, temp2 = -1, temp3 = -1;
		if (i != 0 && j != 0)
			temp1 = dp[i - 1][j - 1][k] + r[i] * g[j];
		if (i != 0 && k != 0)
			temp2 = dp[i - 1][j][k - 1] + r[i] * b[k];
		if (j != 0 && k != 0)
			temp3 = dp[i][j - 1][k - 1] + g[j] * b[k];
		dp[i][j][k] = max({ temp1, temp2, temp3 });
		ans = max(ans, dp[i][j][k]);
	}
	cout << ans;

	return 0;
}