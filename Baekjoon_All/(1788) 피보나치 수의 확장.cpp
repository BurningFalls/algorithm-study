#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* dp = new int[abs(n) + 1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= abs(n); i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	}
	if (n > 0) {
		cout << 1 << endl;
	}
	else if (n == 0) {
		cout << 0 << endl;
	}
	else if (n < 0) {
		if (abs(n) % 2 == 1) {
			cout << 1 << endl;
		}
		else if (abs(n) % 2 == 0) {
			cout << -1 << endl;
		}
	}
	cout << dp[abs(n)];

	return 0;
}