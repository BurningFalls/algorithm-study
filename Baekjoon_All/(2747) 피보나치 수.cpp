#include <iostream>
using namespace std;

int main() {
	int N;
	int dp[46];
	dp[0] = 0;
	dp[1] = 1;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N];

	return 0;
}