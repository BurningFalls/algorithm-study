#include <iostream>
using namespace std;

int main() {
	int K;
	int dp[46][2];
	cin >> K;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= K; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
	}
	cout << dp[K][0] << " " << dp[K][1];

	return 0;
}