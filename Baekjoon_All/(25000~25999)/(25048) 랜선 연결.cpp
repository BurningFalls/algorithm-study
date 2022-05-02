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

struct NODE {
	ll port;
	ll cost;
};

int main() {
	FASTIO;
	int N, M;
	cin >> N;
	vector<NODE> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i].port >> v[i].cost;
	}
	cin >> M;
	if (M == 1) {
		cout << 0;
		return 0;
	}
	vector<ll> dp(M + 1, LINF);
	dp[0] = 0;
	FOR(i, 0, N - 1) {
		ROF(j, M - (v[i].port - 2), 1) {
			if (dp[j] == LINF) continue;
			dp[j + (v[i].port - 2)] = min(dp[j + (v[i].port - 2)], dp[j] + v[i].cost);
		}
		if (v[i].port - 1 <= M) {
			dp[v[i].port - 1] = min(dp[v[i].port - 1], v[i].cost);
		}
	}
	cout << (dp[M] == LINF ? -1 : dp[M]);

	return 0;
}