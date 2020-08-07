#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	int* vip = new int[M + 2];
	int* dp = new int[41];
	int result = 1;
	vip[0] = 0;
	for (int i = 1; i <= M; i++) {
		cin >> vip[i];
	}
	vip[M + 1] = N + 1;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 1; i <= M + 1; i++) {
		result *= dp[vip[i] - vip[i - 1] - 1];
	}
	cout << result << endl;

	return 0;
}