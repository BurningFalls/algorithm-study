#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int dp[100001] = { 0, };
	cin >> N;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0) {
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}
	cout << dp[N] << endl;

	return 0;
}