#include <iostream>
using namespace std;

int main() {
	int N;
	long long int dp[50001][2];

	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[2][0] = dp[1][0] + dp[1][1];
	dp[2][1] = 0;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000009;
		dp[i][1] = dp[i - 2][0];
	}

	cout << (dp[N][0] + dp[N][1]) % 1000000009;



	return 0;
}