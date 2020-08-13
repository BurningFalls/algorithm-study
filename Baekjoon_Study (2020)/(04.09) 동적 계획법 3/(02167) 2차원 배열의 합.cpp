#include <iostream>
using namespace std;

int main() {
	int N, M;
	int arr[301][301];
	int dp[301][301] = { 0, };
	int K;
	int i, j, x, y;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i <= M; i++)
		dp[0][i] = 0;
	for (int i = 0; i <= N; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}

	cin >> K;
	for (int a = 0; a < K; a++) {
		cin >> i >> j >> x >> y;
		cout << dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1] << "\n";
	}

	return 0;
}