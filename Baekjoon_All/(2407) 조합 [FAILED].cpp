#include <iostream>
using namespace std;

int main() {
	int n, m;
	long long int dp[101][101] = { 0, };

	for (int i = 1; i <= 100; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= i - 1; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cin >> n >> m;
	cout << dp[n][m] << endl;

	return 0;
}