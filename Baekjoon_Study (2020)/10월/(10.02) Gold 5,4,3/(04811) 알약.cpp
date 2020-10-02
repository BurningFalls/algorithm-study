#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll dp[61][32] = { 0, };

int main() {
	FASTIO;
	FOR(i, 1, 60) {
		dp[i][1] = 1;
		FOR(j, 2, i / 2 + 1) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	int N;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		cout << dp[2 * N][N + 1] << "\n";
	}

	return 0;
}