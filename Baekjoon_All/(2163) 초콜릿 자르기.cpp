#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int dp[90001];
	cin >> N >> M;
	dp[1] = 0;
	for (int i = 2; i <= 90000; i++) {
		dp[i] = dp[i - 1] + 1;
	}
	cout << dp[N * M] << endl;

	return 0;
}