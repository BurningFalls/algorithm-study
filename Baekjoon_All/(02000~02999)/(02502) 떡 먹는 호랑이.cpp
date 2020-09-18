#include <iostream>
using namespace std;

int main() {
	int D, K;
	int dp[31][2];
	int A = 1, B = 1;
	bool flag = false;
	cin >> D >> K;
	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[2][0] = 0;
	dp[2][1] = 1;
	for (int i = 3; i <= D; i++) {
		dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
		dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
	}
	while (true) {
		B = A;
		while (dp[D][0] * A + dp[D][1] * B <= K) {
			if (dp[D][0] * A + dp[D][1] * B == K) {
				flag = true;
				break;
			}
			else
				B++;
		}
		if (flag)
			break;
		else
			A++;
	}
	cout << A << "\n" << B;

	return 0;
}