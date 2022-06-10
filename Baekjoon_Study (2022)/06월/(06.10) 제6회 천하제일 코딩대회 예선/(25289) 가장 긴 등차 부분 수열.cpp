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
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> dp(101);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}

	int ans = 0;
	FOR(d, -99, 99) {
		fill(ALL(dp), 0);
		FOR(i, 0, N - 1) {
			if (A[i] - d < 1 || A[i] - d > 100) {
				dp[A[i]] = 1;
			}
			else {
				dp[A[i]] = dp[A[i] - d] + 1;
			}
			ans = max(ans, dp[A[i]]);
		}
	}
	cout << ans;

	return 0;
}