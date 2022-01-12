#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MOD 1000000007

char str[2501];
int dp[2501][2501][2] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> str[i];
	}
	if (str[1] == '0') {
		dp[1][1][1] = 1;
	}
	else if (str[1] != '0') {
		dp[1][1][0] = 1;
	}
	FOR(i, 2, N) {
		FOR(j, 1, i) {
			if (str[i] == '0') {
				dp[i][j][0] = dp[i - 1][j][0];
				dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % MOD;
			}
			else if (str[i] != '0') {
				dp[i][j][0] = ((dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % MOD + dp[i - 1][j][0]) % MOD;
			}
		}
	}
	cout << (dp[N][K][0] + dp[N][K][1]) % MOD;

	return 0;
}