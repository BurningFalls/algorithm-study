#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int K;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> K;
		int* arr = new int[K + 1];
		int** dp = new int* [K + 1];
		for (int i = 0; i <= K; i++) {
			dp[i] = new int[K + 1];
		}
		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= K; j++) {
				dp[i][j] = 0;
			}
		}
		/*
		dp[1][1] = 0
		dp[2][2] = 0
		dp[1][2] = (dp[1][1] + dp[2][2]) + arr[1~2]
		dp[3][3] = 0
		dp[2][3] = (dp[2][2] + dp[3][3]) + arr[2~3]
		dp[1][3] = min(dp[1][2] + dp[3][3], dp[1][1] + dp[2][3]) + arr[1~3]
		dp[4][4] = 0
		dp[3][4] = (dp[3][3] + dp[4][4]) + arr[3~4]
		dp[2][4] = min(dp[2][3] + dp[4][4], dp[2][2] + dp[3][4]) + arr[2~4]
		dp[1][4] = min(dp[1][3] + dp[4][4], dp[1][2] + dp[3][4], dp[1][1] + dp[2][4])
					+ arr[1~4]
		*/

		for (int i = 1; i <= K; i++) {
			for (int j = i; j >= 1; j--) {
				for (int k = i - 1; k >= j; k--) {
					if (dp[j][i] == 0) {
						dp[j][i] = dp[j][k] + dp[k + 1][i];
					}
					else {
						dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i]);
					}
				}
				if (j != i) {
					for (int k = j; k <= i; k++) {
						dp[j][i] += arr[k];
					}
				}
			}
		}
		cout << dp[1][K] << endl;
	}


	return 0;
}