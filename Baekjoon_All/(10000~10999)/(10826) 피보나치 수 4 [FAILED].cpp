#include <iostream>
using namespace std;

int main() {
	int n;
	int dp[10001];
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];

	return 0;
}