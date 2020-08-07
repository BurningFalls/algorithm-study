#include <iostream>
using namespace std;

int main() {
	int N;
	long long int dp[16];
	cin >> N;
	dp[1] = 3;
	for (int i = 2; i <= 15; i++) {
		dp[i] = dp[i - 1] * 2 - 1;
	}
	cout << dp[N] * dp[N] << endl;

	return 0;
}