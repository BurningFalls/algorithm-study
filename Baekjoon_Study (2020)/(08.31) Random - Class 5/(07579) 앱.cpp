#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int m[101];
int c[101];
int dp[101][10001] = { 0, };

int main() {
	FASTIO;
	int N, M;
	int ans = INF;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> m[i];
	FOR(i, 1, N)
		cin >> c[i];
	dp[1][c[1]] = m[1];
	FOR(i, 2, N) {
		FOR(j, 0, 10000) {
			if (j - c[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
			else
				dp[i][j] = dp[i - 1][j];
			if (dp[i][j] >= M)
				ans = min(ans, j);
		}
	}
	cout << ans;

	return 0;
}