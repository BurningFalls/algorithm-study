#include <iostream>
using namespace std;

int main() {
	int dp[11][12];
	int N, K;
	cin >> N >> K;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 10; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[N][K];

	return 0;
}