#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int dp[1001][10];
	int sum = 0;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			sum = 0;
			for (int k = 0; k <= j; k++) {
				sum = (sum + dp[i - 1][k]) % 10007;
			}
			dp[i][j] = sum;
		}
	}
	sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[N][i]) % 10007;
	}
	cout << sum << endl;

	return 0;
}