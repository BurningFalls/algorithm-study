#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int** dp = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		dp[i] = new int[K + 1];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= K; i++) {
		dp[0][i] = 1;
	}
	for (int i = 0; i <= N; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			for (int k = 0; k <= i; k++) {
				dp[i][j] = (dp[i][j] + dp[k][j - 1]) % 1000000000;
			}
		}
	}
	cout << dp[N][K] << endl;


	return 0;
}