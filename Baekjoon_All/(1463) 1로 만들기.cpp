#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	int N;
	int way1, way2, way3;
	cin >> N;

	dp[N] = 0;
	for (int i = N - 1; i >= 1; i--) {
		way1 = dp[i + 1] + 1;
		if (i * 2 <= N)
			way2 = dp[i * 2] + 1;
		else
			way2 = way1;
		if (i * 3 <= N)
			way3 = dp[i * 3] + 1;
		else
			way3 = way1;
		dp[i] = min({ way1, way2, way3 });
	}

	cout << dp[1];

	return 0;
}