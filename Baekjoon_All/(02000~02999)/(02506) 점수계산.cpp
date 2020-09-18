#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[101];
	int dp[101] = { 0, };
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	sum += dp[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] == 0) continue;
		if (arr[i - 1] == 0) {
			dp[i] = 1;
		}
		else if (arr[i - 1] == 1) {
			dp[i] = dp[i - 1] + 1;
		}
		sum += dp[i];
	}
	cout << sum;

	return 0;
}