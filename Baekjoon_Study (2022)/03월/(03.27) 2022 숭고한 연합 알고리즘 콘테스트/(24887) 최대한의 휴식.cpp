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

int main() {
	FASTIO;
	ll N, M;
	cin >> N >> M;
	vector<ll> W(N + 1);
	ll maxi = 0;
	ll sum = 0;
	FOR(i, 1, N) {
		cin >> W[i];
		maxi = max(maxi, W[i]);
		sum += W[i];
	}
	if (sum < M) {
		cout << -1;
		return 0;
	}
	if (maxi >= M) {
		cout << "Free!";
		return 0;
	}

	int left = 1, right = N - 1;
	int ans = 0;
	vector<ll> dp(N + 1, 0);
	while (left <= right) {
		int mid = (left + right) / 2;

		FOR(i, 1, mid) {
			dp[i] = max(dp[i - 1], W[i]);
		}
		FOR(i, mid + 1, N) {
			dp[i] = max(dp[i - 1], W[i] + dp[i - mid]);
		}

		if (dp[N] >= M) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else if (dp[N] < M) {
			right = mid - 1;
		}
	}
	cout << ans - 1;

	return 0;
}