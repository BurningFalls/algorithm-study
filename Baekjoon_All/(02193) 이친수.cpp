#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long int dp[90];
	dp[0] = 1; // 1
	dp[1] = 1; // 10
	cin >> N;
	for (int i = 2; i < N; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[N - 1];
	return 0;
}