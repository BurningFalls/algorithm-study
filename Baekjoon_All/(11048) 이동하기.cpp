#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int** arr = new int* [N + 1];
	int** dp = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		arr[i] = new int[M + 1];
		dp[i] = new int[M + 1];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + arr[i][j];
		}
	}
	cout << dp[N][M] << endl;

	return 0;
}