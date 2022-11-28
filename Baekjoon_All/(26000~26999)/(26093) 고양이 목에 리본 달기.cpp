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
	int N, K;
	cin >> N >> K;
	vector<vector<int>> v(N + 1, vector<int>(K + 1));
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	FOR(i, 1, N) {
		FOR(j, 1, K) {
			cin >> v[i][j];
		}
	}
	int pmax1 = 0, pmax2 = 0;
	int max1 = 0, max2 = 0;
	FOR(i, 1, N) {
		FOR(j, 1, K) {
			if (dp[i - 1][j] == pmax1) {
				dp[i][j] = pmax2 + v[i][j];
			}
			else {
				dp[i][j] = pmax1 + v[i][j];
			}
			if (max1 <= dp[i][j]) {
				max2 = max1;
				max1 = dp[i][j];
			}
			else if (max2 <= dp[i][j]) {
				max2 = dp[i][j];
			}
		}
		pmax1 = max1, pmax2 = max2;
	}

	int ans = 0;
	FOR(i, 1, K) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans;

	return 0;
}