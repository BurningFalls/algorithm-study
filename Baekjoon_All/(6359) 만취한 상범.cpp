#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int T;
	int n;
	int dp[101] = { 0, };
	int temp;

	dp[1] = 1;
	for (int i = 2; i <= 100; i++) {
		temp = 0;
		for (int j = 1; j <= sqrt(i); j++) {
			if (i == j * j) {
				temp = j;
				break;
			}
		}
		if (temp == 0) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}