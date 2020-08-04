#include <iostream>
using namespace std;

int main() {
	int R, C, W;
	int dp[30][30];
	long long int sum = 0;
	for (int i = 1; i <= 29; i++) {
		dp[i][1] = 1;
		for (int j = 2; j <= i - 1; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
		dp[i][i] = 1;
	}
	cin >> R >> C >> W;
	for (int i = R; i < R + W; i++) {
		for (int j = C; j <= C + i - R; j++) {
			sum += dp[i][j];
		}
	}
	cout << sum;

	return 0;
}