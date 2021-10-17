#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define MOD 1000000007

ll dp[1000001][5];

int main() {
	FASTIO;
	int T;
	cin >> T;
	dp[1][0] = 3;
	dp[1][1] = 2;
	dp[1][2] = 2;
	dp[1][3] = 3;
	dp[1][4] = 3;
	FOR(i, 2, 1000000) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
		dp[i][3] = dp[i][0];
		dp[i][4] = dp[i][0];
	}
	while (T--) {
		int N;
		cin >> N;
		cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD << "\n";
	}

	return 0;
}