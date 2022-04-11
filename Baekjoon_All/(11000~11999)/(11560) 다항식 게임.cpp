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

ll dp[21][211] = { 0, };

int main() {
	FASTIO;
	dp[1][0] = 1;
	dp[1][1] = 1;
	FOR(i, 2, 20) {
		ll sum = 0;
		FOR(j, 0, i) {
			sum += dp[i - 1][j];
			dp[i][j] = sum;
		}
		FOR(j, i + 1, i * (i + 1) / 2) {
			sum += dp[i - 1][j];
			sum -= dp[i - 1][j - i - 1];
			dp[i][j] = sum;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int K, N;
		cin >> K >> N;
		cout << dp[K][N] << "\n";
	}

	return 0;
}