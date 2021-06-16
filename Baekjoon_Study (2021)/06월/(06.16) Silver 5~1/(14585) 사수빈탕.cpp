#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[301][301];
ll dp[301][301] = { 0, };

int main() {
	FASTIO;
	int N, M;
	
	cin >> N >> M;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
		arr[y][x] = 1;
	}
	FOR(i, 0, min(M, 300)) {
		FOR(j, 0, min(M, 300)) {
			if (i == 0 && j == 0)
				continue;
			if (i == 0)
				dp[i][j] = dp[i][j - 1];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (arr[i][j] && (i + j) < M) {
				dp[i][j] += (ll)M - (i + j);
			}
		}
	}
	cout << dp[min(M, 300)][min(M, 300)];

	return 0;
}