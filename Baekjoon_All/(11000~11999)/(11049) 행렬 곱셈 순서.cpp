#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* R = new int[N + 1];
	int* C = new int[N + 1];
	int** dp = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		dp[i] = new int[N + 1];
	}
	for (int i = 1; i <= N; i++) {
		cin >> R[i] >> C[i];
	}
	/*dp[1][1] = 0;
	dp[2][2] = 0;
	dp[1][2] = dp[1][1] + dp[2][2] + R[1] * R[2] * C[2];
	dp[3][3] = 0;
	dp[2][3] = dp[2][2] + dp[3][3] + R[2] * R[3] * C[3];
	dp[1][3] = max(dp[1][2] + dp[3][3] + R[1] * R[3] * C[3],
		dp[1][1] + dp[2][3] + R[1] * R[2] * C[3]);
	dp[4][4] = 0;
	dp[3][4] = dp[3][3] + dp[4][4] + R[3] * R[4] * C[4];
	dp[2][4] = max(dp[2][3] + dp[4][4] + R[2] * R[4] * C[4],
		dp[2][2] + dp[3][4] + R[2] * R[3] * C[4]);
	dp[1][4] = max(dp[1][3] + dp[4][4] + R[1] * R[4] * C[4],
		dp[1][2] + dp[3][4] + R[1] * R[3] * C[4],
		dp[1][1] + dp[2][4] + R[1] * R[2] * C[4]);*/

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i; j >= 1; j--) {
			for (int k = i - 1; k >= j; k--) {
				if (dp[j][i] == 0) {
					dp[j][i] = dp[j][k] + dp[k + 1][i] + R[j] * R[k + 1] * C[i];
				}
				else {
					dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + R[j] * R[k + 1] * C[i]);
				}
			}
		}
	}

	cout << dp[1][N] << endl;

	return 0;
}