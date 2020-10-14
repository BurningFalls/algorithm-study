#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

ll dp[101][101][101] = { 0, };

int main() {
	FASTIO;
	int N, L, R;
	cin >> N >> L >> R;
	dp[1][1][1] = 1;
	FOR(i, 2, N) {
		FOR(j, 1, N) {
			FOR(k, 1, N) {
				if (j == 1 && k == 1) continue;
				if (j + k > N + 1) continue;
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % MOD;
			}
		}
	}
	cout << dp[N][L][R];

	return 0;
}