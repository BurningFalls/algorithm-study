#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
int dp[501][501];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
		for (int j = 1; j <= i - 1; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
		dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
	}

	cout << *max_element(dp[n - 1], dp[n - 1] + n);

	return 0;
}