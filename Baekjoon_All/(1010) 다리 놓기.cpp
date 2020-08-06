#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int N, M;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N >> M;
		long long int* dp = new long long int[N + 1];
		dp[1] = M;
		for (int i = 2; i <= N; i++) {
			dp[i] = dp[i - 1] * (M + 1 - i) / i;
		}
		cout << dp[N] << endl;
	}

	return 0;
}