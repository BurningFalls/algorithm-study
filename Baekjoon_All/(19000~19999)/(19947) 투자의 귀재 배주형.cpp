#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll H, Y;
	ll dp[11];
	memset(dp, -1, sizeof(dp));
	cin >> H >> Y;
	dp[0] = H;
	int inter;
	FOR(i, 1, Y) {
		inter = dp[i - 1] * 5 / 100;
		dp[i] = dp[i - 1] + inter;
		if (i >= 3 && dp[i - 3] != -1) {
			inter = dp[i - 3] * 20 / 100;
			dp[i] = max(dp[i - 3] + inter, dp[i]);
		}
		if (i >= 5 && dp[i - 5] != -1) {
			inter = dp[i - 5] * 35 / 100;
			dp[i] = max(dp[i - 5] + inter, dp[i]);
		}
	}
	cout << dp[Y];

	return 0;
}