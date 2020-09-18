#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int** dp = new int* [N];
	for (int i = 0; i <= N; i++) {
		dp[i] = new int[i + 1];
	}
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
		dp[i][i] = 1;
	}
	cout << dp[N][K] << endl;

	return 0;
}