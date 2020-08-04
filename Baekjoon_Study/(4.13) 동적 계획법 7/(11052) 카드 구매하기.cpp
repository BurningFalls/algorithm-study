#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int P[1001];
	int dp[1001];
	int maximum;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	dp[0] = 0;
	dp[1] = P[1];
	//dp[2] = max(dp[0] + P[2], dp[1] + P[1]);
	//dp[3] = max({ dp[0] + P[3], dp[1] + P[2], dp[2] + P[1] });
	//dp[4] = max({ dp[0] + P[4], dp[1] + P[3], dp[2] + P[2], dp[3] + P[1] });

	for (int i = 2; i <= N; i++) {
		maximum = 0;
		for (int j = 0; j < i; j++) {
			maximum = max(maximum, dp[j] + P[i - j]);
		}
		dp[i] = maximum;
	}
	cout << dp[N];

	return 0;
}