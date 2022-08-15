#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<char> v(N + 1);
	vector<vector<ll>> dp(N + 1, vector<ll>(4, 0));
	FOR(i, 1, N) {
		cin >> v[i];
	}
	FOR(i, 1, N) {
		FOR(j, 0, 3) {
			dp[i][j] = dp[i - 1][j];
		}
		if (v[i] == 'D') {
			dp[i][0] += 1;
		}
		else if (v[i] == 'K') {
			dp[i][1] += dp[i - 1][0];
		}
		else if (v[i] == 'S') {
			dp[i][2] += dp[i - 1][1];
		}
		else if (v[i] == 'H') {
			dp[i][3] += dp[i - 1][2];
		}
	}
	cout << dp[N][3];

	return 0;
}