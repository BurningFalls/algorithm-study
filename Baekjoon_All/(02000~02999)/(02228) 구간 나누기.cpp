#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 4000000

int dp[101][2][51];
int arr[101];

int main() {
	FASTIO;
	FOR(i, 0, 100) FOR(j, 0, 1) FOR(k, 0, 50)
		dp[i][j][k] = -INF;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> arr[i];
	dp[1][0][0] = 0;
	dp[1][1][1] = arr[1];
	FOR(i, 2, N) {
		FOR(j, 0, ceil((double)N / 2)) {
			if (j > ceil((double)i / 2)) continue;
			dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j]);
			if (j == 0)
				dp[i][1][j] = dp[i - 1][1][j];
			else
				dp[i][1][j] = max(dp[i - 1][0][j - 1], dp[i - 1][1][j]);
			if (dp[i][1][j] != -INF)
				dp[i][1][j] += arr[i];
		}
	}
	cout << max(dp[N][0][M], dp[N][1][M]);

	return 0;
}