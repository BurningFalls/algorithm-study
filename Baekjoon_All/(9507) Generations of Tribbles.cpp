#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	int* arr = new int[T];
	int n;
	long long int* dp = new long long int[68];

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 67; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}

	for (int a = 0; a < T; a++) {
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}