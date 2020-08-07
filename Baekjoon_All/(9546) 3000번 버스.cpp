#include <iostream>
using namespace std;

int main() {
	int T;
	int k;
	int dp[31];
	dp[0] = 0;
	for (int i = 1; i <= 30; i++) {
		dp[i] = (dp[i - 1] + 0.5) * 2;
	}

	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> k;
		cout << dp[k] << endl;
	}


	return 0;
}