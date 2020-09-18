#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];
int arr[100001];

int main() {
	int N;
	int maximum;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	maximum = dp[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		maximum = max(maximum, dp[i]);
	}
	cout << maximum;

	return 0;
}