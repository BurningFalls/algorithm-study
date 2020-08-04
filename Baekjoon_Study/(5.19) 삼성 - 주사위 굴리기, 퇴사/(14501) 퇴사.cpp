#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int dp[16];
	int T[16];
	int P[16];
	int temp_max;
	int dp_max = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	dp[0] = 0;
	T[0] = 0;
	P[0] = 0;
	for (int i = 1; i <= N; i++) {
		if (i + T[i] - 1 > N)
			P[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		temp_max = 0;
		for (int j = 0; j < i; j++) {
			if (j + T[j] <= i) {
				temp_max = max(temp_max, dp[j] + P[i]);
			}
		}
		dp[i] = temp_max;
		dp_max = max(dp_max, dp[i]);
	}
	cout << dp_max;

	return 0;
}