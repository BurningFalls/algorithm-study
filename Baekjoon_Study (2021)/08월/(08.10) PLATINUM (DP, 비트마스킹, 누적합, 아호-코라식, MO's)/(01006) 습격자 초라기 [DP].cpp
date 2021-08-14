#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, W;
int arr[2][10001];
int dp[10001][3];
int ans;

void DP() {
	FOR(i, 2, N) {
		int up = arr[0][i - 1] + arr[0][i] <= W ? 1 : 2;
		int down = arr[1][i - 1] + arr[1][i] <= W ? 1 : 2;
		int up_down = arr[0][i] + arr[1][i] <= W ? 1 : 2;

		dp[i][0] = min({ dp[i - 1][0] + up_down, dp[i - 2][0] + up + down, dp[i - 1][1] + up + 1, dp[i - 1][2] + 1 + down });
		dp[i][1] = min({ dp[i - 1][2] + down, dp[i - 1][0] + 1 });
		dp[i][2] = min({ dp[i - 1][1] + up, dp[i - 1][0] + 1 });
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		ans = INF;
		cin >> N >> W;
		FOR(i, 0, 1) {
			FOR(j, 1, N) {
				cin >> arr[i][j];
			}
		}

		if (N == 1)
			ans = arr[0][1] + arr[1][1] <= W ? 1 : 2;
		else {
			int arr_01 = arr[0][1];
			int arr_11 = arr[1][1];
			dp[1][0] = arr[0][1] + arr[1][1] <= W ? 1 : 2;
			dp[1][1] = 1;
			dp[1][2] = 1;
			DP();
			ans = min(ans, dp[N][0]);

			dp[1][0] = 2;
			dp[1][1] = 1;
			dp[1][2] = 1;
			if (arr[0][1] + arr[0][N] <= W) {
				arr[0][1] = INF;
				DP();
				ans = min(ans, dp[N][1]);
				arr[0][1] = arr_01;
			}
			if (arr[1][1] + arr[1][N] <= W) {
				arr[1][1] = INF;
				DP();
				ans = min(ans, dp[N][2]);
				arr[1][1] = arr_11;
			}
			if (arr[0][1] + arr[0][N] <= W && arr[1][1] + arr[1][N] <= W) {
				arr[0][1] = INF;
				arr[1][1] = INF;
				DP();
				ans = min(ans, dp[N - 1][0]);
				arr[0][1] = arr_01;
				arr[1][1] = arr_11;
			}
		}
		cout << ans << "\n";
	}


	return 0;
}