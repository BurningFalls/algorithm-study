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
	int N, M, A, B;
	cin >> N >> M >> A >> B;
	vector<pii> v(M);
	vector<int> dp(100001, INF);
	vector<int> check(100002, 0);
	FOR(i, 0, M - 1) {
		cin >> v[i].first >> v[i].second;
		check[v[i].first] += 1;
		check[v[i].second + 1] -= 1;
	}
	FOR(i, 1, 100000) {
		check[i] += check[i - 1];
	}
	dp[0] = 0;
	FOR(i, 0, 100000) {
		if (check[i] != 0) continue;
		if (i - A >= 0 && dp[i - A] != INF) {
			dp[i] = min(dp[i], dp[i - A] + 1);
		}
		if (i - B >= 0 && dp[i - B] != INF) {
			dp[i] = min(dp[i], dp[i - B] + 1);
		}
	}
	cout << (dp[N] == INF ? -1 : dp[N]);

	return 0;
}