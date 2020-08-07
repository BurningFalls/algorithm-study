#include <iostream>
using namespace std;

int main() {
	int T;
	int K, N;
	long long int dp[21][211];
	int sum;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 20; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i * (i - 1) / 2; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][i * (i + 1) / 2 - j] = dp[i][j];
		}
		dp[i][i * (i + 1) / 2] = 1;
	}

	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> K >> N;
		cout << dp[K][N] << "\n";
	}

	return 0;
}