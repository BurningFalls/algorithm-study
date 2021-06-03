#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000009

ll dp[100001][2] = { 0, };

int main() {
	FASTIO;
	dp[1][0] = 1, dp[1][1] = 0;
	dp[2][0] = 1, dp[2][1] = 1;
	dp[3][0] = 2, dp[3][1] = 2;
	FOR(i, 4, 100000) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % MOD;
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << dp[N][0] << " " << dp[N][1] << "\n";
	}


	return 0;
}