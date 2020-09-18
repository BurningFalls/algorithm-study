#include <iostream>
using namespace std;

int main() {
	int N;
	int dp[11][10] = { 0, };
	int sum = -1;
	int dif;
	cin >> N;
	if (N >= 1023) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i <= 9; i++) {
			dp[1][i] = 1;
		}
		for (int i = 2; i <= 10; i++) {
			for (int j = i - 1; j <= 9; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			}
		}

		for (int i = 1; i <= 10; i++) {
			for (int j = 0; j <= 9; j++) {
				sum += dp[i][j];
				if (sum >= N) {
					cout << j;
					dif = sum - N + 1;
					i--;
					j--;
					while (i >= 1 && j >= 0 && dif != 0) {
						if (dp[i][j] >= dif) {
							cout << j;
							i--;
							j--;
						}
						else if (dp[i][j] < dif) {
							dif = dif - dp[i][j];
							j--;
						}
					}
					j = 10;
					i = 11;
				}
			}
		}
	}

	return 0;
}