#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool dp[101][101][5001] = { 0, };

int main() {
	FASTIO;
	for (int i = 2; i <= 100; i += 2) {
		dp[i][1][0] = 1;
		dp[1][i][i / 2] = 1;
	}
	FOR(i, 1, 100)
		dp[i][2][i] = 1;
	FOR(i, 2, 100) {
		FOR(j, 2, 100) {
			if ((i * j) % 2 == 1) continue;
			FOR(k, 0, i * j / 2) {
				if (i == k && j == 2) continue;
				if (k >= 2)
					dp[i][j][k] = (dp[i][j - 1][k] || dp[i][j - 2][k - 2]);
				else
					dp[i][j][k] = dp[i][j - 1][k];
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		cout << ((dp[n][m][k]) ? "YES" : "NO") << "\n";
	}


	return 0;
}