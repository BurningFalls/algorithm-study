#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MOD 1000000003

ll dp[1001][1001] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	dp[0][0] = 1;
	FOR(i, 1, N) {
		dp[i][0] = 1;
		dp[i][1] = i;
		FOR(j, 2, (i + 1) / 2) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;

	return 0;
}