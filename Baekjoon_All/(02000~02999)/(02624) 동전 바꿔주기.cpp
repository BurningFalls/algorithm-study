#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[10001][101] = { 0, };

int main() {
	FASTIO;
	int T, K;
	cin >> T >> K;
	FOR(i, 1, K) {
		int p, n;
		cin >> p >> n;
		dp[0][i - 1] = 1;
		FOR(j, 1, n) {
			FOR(k, p * j, T) {
				dp[k][i] += dp[k - (p * j)][i - 1];
			}
		}
		FOR(j, 1, T) {
			dp[j][i] += dp[j][i - 1];
		}
	}
	cout << dp[T][K];

	return 0;
}