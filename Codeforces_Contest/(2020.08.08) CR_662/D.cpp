#include <bits/stdc++.h>
using namespace std;

#define MAX 2001

char Map[2001][2001];
int dp1[2001][2001];
int dp2[2001][2001];
int dp3[2001][2001];
int dp4[2001][2001];
int dp[2001][2001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp1[i][j] = 1;
			dp2[i][j] = 1;
			dp3[i][j] = 1;
			dp4[i][j] = 1;
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
				dp[i][j] = 1;
			else
				dp[i][j] = MAX;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 2; j++) {
			if (Map[i][j] == Map[i][j - 1] && Map[i][j] == Map[i - 1][j])
				dp1[i][j] = min(dp1[i][j - 1], dp1[i - 1][j]) + 1;
			dp[i][j] = min(dp[i][j], dp1[i][j]);
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = m - 2; j >= 1; j--) {
			if (Map[i][j] == Map[i][j + 1] && Map[i][j] == Map[i - 1][j])
				dp2[i][j] = min(dp2[i][j + 1], dp2[i - 1][j]) + 1;
			dp[i][j] = min(dp[i][j], dp2[i][j]);
		}
	}
	for (int i = n - 2; i >= 1; i--) {
		for (int j = 1; j <= m - 2; j++) {
			if (Map[i][j] == Map[i][j - 1] && Map[i][j] == Map[i + 1][j])
				dp3[i][j] = min(dp3[i][j - 1], dp3[i + 1][j]) + 1;
			dp[i][j] = min(dp[i][j], dp3[i][j]);
		}
	}
	for (int i = n - 2; i >= 1; i--) {
		for (int j = m - 2; j >= 1; j--) {
			if (Map[i][j] == Map[i][j + 1] && Map[i][j] == Map[i + 1][j])
				dp4[i][j] = min(dp4[i][j + 1], dp4[i + 1][j]) + 1;
			dp[i][j] = min(dp[i][j], dp4[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += dp[i][j];
		}
	}
	cout << ans;

	return 0;
}