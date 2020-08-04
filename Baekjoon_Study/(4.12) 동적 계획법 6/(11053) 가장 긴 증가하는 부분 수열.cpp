#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[1001];
	int dp[1001];
	int maximum;
	int dp_max = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		maximum = 0;
		for (int j = 1; j <= i - 1; j++) {
			if (arr[i] > arr[j]) {
				maximum = max(maximum, dp[j]);
			}
		}
		dp[i] = maximum + 1;
		dp_max = max(dp_max, dp[i]);
	}

	cout << dp_max;

	return 0;
}