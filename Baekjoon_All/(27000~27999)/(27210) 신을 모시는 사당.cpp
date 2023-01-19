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
	vector<int> v(N);
	vector<int> dp(N);
	int ans = 1;
	FOR(i, 0, N - 1) {
		cin >> v[i];
		if (v[i] == 2) {
			v[i] = -1;
		}
	}

	dp[0] = v[0];
	FOR(i, 1, N - 1) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		ans = max(ans, dp[i]);
	}

	dp[0] = -v[0];
	FOR(i, 1, N - 1) {
		dp[i] = max(dp[i - 1] - v[i], -v[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}