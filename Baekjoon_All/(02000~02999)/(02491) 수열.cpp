#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
	int N;
	int maximum = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] >= arr[i - 1])
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 1;
		maximum = max(maximum, dp[i]);
	}
	dp[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] >= arr[i + 1])
			dp[i] = dp[i + 1] + 1;
		else
			dp[i] = 1;
		maximum = max(maximum, dp[i]);
	}
	cout << maximum;

	return 0;
}