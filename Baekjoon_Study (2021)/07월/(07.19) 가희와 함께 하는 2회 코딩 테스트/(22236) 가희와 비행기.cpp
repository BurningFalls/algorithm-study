#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll dp[4001][4001] = { 0, };

int main() {
	FASTIO;
	int D, M;
	cin >> D >> M;
	dp[1][1] = 1;
	FOR(i, 2, D) {
		FOR(j, (i + 1) / 2, i) {
			if (i % 2 == 1 && j == (i + 1) / 2)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % M;
		}
	}
	cout << dp[D][D / 2];

	return 0;
}