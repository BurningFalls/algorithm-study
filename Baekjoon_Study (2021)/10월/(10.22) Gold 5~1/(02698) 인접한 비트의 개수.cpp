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

int dp[101][2][101] = { 0, };

int main() {
	FASTIO;
	dp[1][0][0] = 1;
	dp[1][1][0] = 1;
	FOR(i, 2, 100) {
		dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][1][0];
		dp[i][1][0] = dp[i - 1][0][0];
		FOR(j, 1, i - 1) {
			dp[i][0][j] = dp[i - 1][0][j] + dp[i - 1][1][j];
			dp[i][1][j] = dp[i - 1][0][j] + dp[i - 1][1][j - 1];
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		cout << dp[N][0][K] + dp[N][1][K] << "\n";
	}

	return 0;
}