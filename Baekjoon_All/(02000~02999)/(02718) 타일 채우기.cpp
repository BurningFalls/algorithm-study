#include <iostream>
using namespace std;

int dp[30][13];

int DP(int n, int bm) {
	int temp;
	if (dp[n][bm] != -1)
		return dp[n][bm];
	if (bm == 0)
		temp = DP(n - 2, 0) + DP(n - 1, 0) + DP(n - 1, 3) + DP(n - 1, 9) + DP(n - 1, 12);
	else if (bm == 3)
		temp = DP(n - 1, 0) + DP(n - 1, 12);
	else if (bm == 6)
		temp = DP(n - 1, 9);
	else if (bm == 9)
		temp = DP(n - 1, 0) + DP(n - 1, 6);
	else if (bm == 12)
		temp = DP(n - 1, 0) + DP(n - 1, 3);
	dp[n][bm] = temp;
	return dp[n][bm];
}

int main() {
	ios_base::sync_with_stdio(0);
	int T;
	int N;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 13; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1, dp[0][3] = 0, dp[0][6] = 0, dp[0][9] = 0, dp[0][12] = 0;
	dp[1][0] = 1, dp[1][3] = 1, dp[1][6] = 0, dp[1][9] = 1, dp[1][12] = 1;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		cout << DP(N, 0) << "\n";
	}

	return 0;
}