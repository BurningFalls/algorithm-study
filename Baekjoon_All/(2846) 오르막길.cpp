#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[1001];
	int dp[1001][3];
	int max_ans = 0;
	int maximum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1][0] = 1;
	dp[1][1] = arr[1];
	dp[1][2] = arr[1];
	for (int i = 2; i <= N; i++) {
		if (arr[i] > arr[i - 1]) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = arr[i];
		}
		else {
			dp[i][0] = 1;
			dp[i][1] = arr[i];
			dp[i][2] = arr[i];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (maximum < dp[i][0]) {
			maximum = dp[i][0];
		}
	}

	for (int i = 1; i <= N; i++) {
		max_ans = max(max_ans, dp[i][2] - dp[i][1]);
	}
	cout << max_ans;

	return 0;
}