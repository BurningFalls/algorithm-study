#include <iostream>
using namespace std;

int main() {
	int T;
	int L;
	int dp[5001];
	cin >> T;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= 5000; i++) {
		if (i % 2 == 1)
			dp[i] = 0;
		else if (i % 2 == 0)
			dp[i] = (dp[i - 2] * 2) % 1000000007;
	}

	for (int a = 0; a < T; a++) {
		cin >> L;
		cout << dp[L] << "\n";
	}


	return 0;
}