#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N + 1];
	long long int** dp = new long long int* [N + 1];
	for (int i = 0; i <= N; i++) {
		dp[i] = new long long int[21];
	}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 20; j++) {
			dp[i][j] = 0;
		}
	}
	dp[1][arr[1]] = 1;
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + arr[i] <= 20) {
				dp[i][j] += dp[i - 1][j + arr[i]];
			}
			if (j - arr[i] >= 0) {
				dp[i][j] += dp[i - 1][j - arr[i]];
			}
		}
	}
	cout << dp[N - 1][arr[N]] << endl;

	return 0;
}