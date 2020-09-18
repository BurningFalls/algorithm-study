#include <iostream>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int** dp = new int* [N + 1];
	int o_x, o_y;
	if (K == 0) {
		o_x = 1;
		o_y = 1;
	}
	else {
		o_x = (K - 1) % M + 1;
		o_y = (K - 1) / M + 1;
	}
	for (int i = 0; i <= N; i++) {
		dp[i] = new int[M + 1];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = 0;
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= o_y; i++) {
		for (int j = 1; j <= o_x; j++) {
			if (i != 1 || j != 1) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
	}
	for (int i = o_y; i <= N; i++) {
		for (int j = o_x; j <= M; j++) {
			if (i != o_y || j != o_x) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
	}
	cout << dp[N][M] << endl;

	return 0;
}