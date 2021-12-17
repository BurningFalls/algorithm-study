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

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<ll> A(N);
	vector<ll> v;
	ll prev = 0;
	ll sum = 0;
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	sort(ALL(A));
	FOR(i, 0, N - 1) {
		if (i == 0) {
			sum = A[i];
			prev = A[i];
			continue;
		}
		if (A[i] == prev) {
			sum += A[i];
		}
		else {
			v.push_back(sum);
			sum = A[i];
			prev = A[i];
		}
	}
	v.push_back(sum);
	int len = LEN(v);
	vector<vector<ll>> dp(len + 1, vector<ll>(len + 1, 0));
	FOR(i, 0, len) {
		dp[i][0] = 1;
	}
	FOR(j, 1, M) {
		FOR(i, j, len) {
			dp[i][j] = (dp[i - 1][j - 1] * v[i - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[len][M];

	return 0;
}