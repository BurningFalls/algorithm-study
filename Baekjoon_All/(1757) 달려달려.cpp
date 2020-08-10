#include <bits/stdc++.h>
using namespace std;

int D[10001];
int DP[10001][501][2];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int N, M;
	int maximum = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> D[i];
	memset(DP, 0, sizeof(DP));
	DP[1][0][1] = D[1];
	for (int i = 2; i <= N; i++) {
		DP[i][0][0] = max(DP[i - 1][0][0], DP[i - 1][1][0]);
		DP[i][0][1] = max(DP[i - 1][0][0], DP[i - 1][1][0]) + D[i];
		for (int j = 1; j <= M - 1; j++) {
			DP[i][j][0] = max(DP[i - 1][j + 1][0], DP[i - 1][j - 1][1]);
			DP[i][j][1] = DP[i - 1][j - 1][1] + D[i];
		}
		DP[i][M][0] = DP[i - 1][M - 1][1];
		DP[i][M][1] = DP[i - 1][M - 1][1] + D[i];
	}
	cout << max(DP[N][0][0], DP[N][1][0]);

	return 0;
}