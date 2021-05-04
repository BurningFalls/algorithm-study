#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000009

ll dp[1001][1001] = { 0, };

int main() {
	FASTIO;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;
	FOR(i, 4, 1000) {
		FOR(j, 1, i) {
			dp[i][j] = (dp[i - 3][j - 1] + dp[i - 2][j - 1] + dp[i - 1][j - 1]) % MOD;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << dp[N][M] << "\n";
	}


	return 0;
}