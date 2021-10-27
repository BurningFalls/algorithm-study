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
#define MOD 1000000

int dp[1001][2][3] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	dp[1][1][0] = 1;
	FOR(i, 2, N) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
		dp[i][0][1] = dp[i - 1][0][0];
		dp[i][0][2] = dp[i - 1][0][1];
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
		dp[i][1][1] = dp[i - 1][1][0];
		dp[i][1][2] = dp[i - 1][1][1];
	}
	int sum = 0;
	FOR(i, 0, 1) {
		FOR(j, 0, 2) {
			sum = (sum + dp[N][i][j]) % MOD;
		}
	}
	cout << sum;

	return 0;
}