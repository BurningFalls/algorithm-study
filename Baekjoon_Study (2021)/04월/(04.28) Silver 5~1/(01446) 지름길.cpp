#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<pii> v[10001];

int dp[10001];

int main() {
	FASTIO;
	int N, D;
	cin >> N >> D;
	dp[0] = 0;
	FOR(i, 1, N) {
		int s, e, len;
		cin >> s >> e >> len;
		v[e].push_back({ s, len });
	}
	FOR(i, 1, D) {
		dp[i] = dp[i - 1] + 1;
		if (v[i].empty()) continue;
		for (pii x : v[i]) {
			dp[i] = min(dp[i], dp[x.first] + x.second);
		}
	}
	cout << dp[D];

	return 0;
}