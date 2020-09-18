#include <iostream>
using namespace std;

int main() {
	int T;
	int N;
	long long int dp[302];
	long long int ans;
	dp[0] = 0;
	for (int i = 1; i <= 301; i++) {
		dp[i] = dp[i - 1] + i;
	}
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		ans = 0;
		for (int i = 1; i <= N; i++) {
			ans += i * dp[i + 1];
		}
		cout << ans << "\n";
	}

	return 0;
}