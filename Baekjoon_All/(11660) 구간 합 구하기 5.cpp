#include <iostream>
using namespace std;

int arr[1025][1025];
int dp[1025][1025] = { 0, };

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N, M;
	int x1, y1, x2, y2;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}