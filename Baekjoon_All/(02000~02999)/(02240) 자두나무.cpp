#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, W;
	int dp[3][1001][31];
	int max1, max2;
	cin >> T >> W;
	int* arr = new int[T + 1];
	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1001; j++) {
			for (int k = 0; k < 31; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	/*dp[1][1][0] = 0;
	dp[1][1][1] = 0;
	dp[2][1][0] = 0;
	dp[2][1][1] = 1;
	dp[1][2][0] = max(dp[1][1][0], dp[2][1][-1]) + 1;
	dp[1][2][1] = max(dp[1][1][1], dp[2][1][0]) + 1;
	dp[1][2][2] = max(dp[1][1][2], dp[2][1][1]) + 1;
	dp[2][2][0] = max(dp[1][1][-1], dp[2][1][0]);
	dp[2][2][1] = max(dp[1][1][0], dp[2][1][1]);
	dp[2][2][2] = max(dp[1][1][1], dp[2][1][2]);

	dp[1][3][0] = max(dp[1][2][0], dp[2][2][-1]) + 1;
	dp[1][3][1] = max(dp[1][2][1], dp[2][2][0]) + 1;
	dp[1][3][2] = max(dp[1][2][2], dp[2][2][1]) + 1;
	dp[1][3][3] = max(dp[1][2][3], dp[2][2][2]) + 1;
	dp[2][3][0] = max(dp[1][2][-1], dp[2][2][0]);
	dp[2][3][1] = max(dp[1][2][0], dp[2][2][1]);
	dp[2][3][2] = max(dp[1][2][1], dp[2][2][2]);
	dp[2][3][3] = max(dp[1][2][0], dp[2][2][3]);*/

	if (arr[1] == 1) {
		dp[1][1][0] = 1;
		dp[1][1][1] = -1;
		dp[2][1][0] = -1;
		dp[2][1][1] = 0;
	}
	else if (arr[1] == 2) {
		dp[1][1][0] = 0;
		dp[1][1][1] = -1;
		dp[2][1][0] = -1;
		dp[2][1][1] = 1;
	}

	for (int i = 2; i <= T; i++) {
		dp[1][i][0] = dp[1][i - 1][0];
		dp[2][i][0] = dp[2][i - 1][0];
		if (arr[i] == 1 && dp[1][i][0] != -1) {
			dp[1][i][0] += 1;
		}
		if (arr[i] == 2 && dp[2][i][0] != -1) {
			dp[2][i][0] += 1;
		}
		for (int j = 1; j <= min(i, W); j++) {
			dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]);
			dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);
			if (arr[i] == 1 && dp[1][i][j] != -1) {
				dp[1][i][j] += 1;
			}
			if (arr[i] == 2 && dp[2][i][j] != -1) {
				dp[2][i][j] += 1;
			}
		}
	}

	max1 = *max_element(dp[1][T], dp[1][T] + (T + 1));
	max2 = *max_element(dp[2][T], dp[2][T] + (T + 1));

	cout << max(max1, max2) << endl;

	return 0;
}