#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int* arr = new int[n];
	int** dp = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new int[k + 1];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= k; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (arr[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
			}
		}
	}
	cout << dp[n][k] << endl;

	return 0;
}