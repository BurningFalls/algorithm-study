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
#define MOD 987654321

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<vector<int>> dp(100001, vector<int>(10, 0));
	FOR(i, 1, 9) {
		dp[0][i] = 1;
	}
	FOR(i, 1, N - 1) {
		FOR(j, 1, 9) {
			int sum = 0;
			FOR(k, max(1, j - 2), min(9, j + 2)) {
				sum = (sum + dp[i - 1][k]) % MOD;
			}
			dp[i][j] = sum;
		}
	}

	int ans = 0;
	FOR(i, 1, 9) {
		ans = (ans + dp[N - 1][i]) % MOD;
	}
	cout << ans;

	return 0;
}