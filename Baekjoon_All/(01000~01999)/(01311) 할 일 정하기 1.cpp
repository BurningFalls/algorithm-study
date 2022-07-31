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

int N;
vector<vector<int>> v(20, vector<int>(20));
vector<int> dp(1 << 20, INF);

int DP(int node, int bm) {
	if (node == N) {
		return 0;
	}
	int& ret = dp[bm];
	if (ret != INF) {
		return ret;
	}
	FOR(next, 0, N - 1) {
		if (bm & (1 << next)) continue;
		ret = min(ret, DP(node + 1, bm | (1 << next)) + v[node][next]);
	}
	return ret;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> v[i][j];
		}
	}
	cout << DP(0, 0);

	return 0;
}