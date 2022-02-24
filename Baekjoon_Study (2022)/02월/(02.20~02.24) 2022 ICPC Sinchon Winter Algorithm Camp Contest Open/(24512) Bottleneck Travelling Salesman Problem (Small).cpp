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
	int val;
	vector<int> v;
};

int N, M;
vector<vector<int>> cost(9, vector<int>(9, 0));
vector<vector<NODE>> dp(9, vector<NODE>(1 << 9, { -1, vector<int>()}));
vector<int> ans(N);

NODE DP(int node, int bm) {
	if (bm == (1 << N) - 1) {
		vector<int> tmp;
		if (cost[node][0] == 0) {
			return { int(INF), tmp };
		}
		else {
			tmp.push_back(node);
			return { cost[node][0], tmp };
		}
	}
	NODE& ret = dp[node][bm];
	if (ret.val != -1) {
		return ret;
	}
	ret.val = INF;
	FOR(i, 0, N - 1) {
		if (cost[node][i] == 0) continue;
		if (bm & (1 << i)) continue;
		NODE tmp = DP(i, bm | (1 << i));
		if (ret.val > max(tmp.val, cost[node][i])) {
			ret.val = max(tmp.val, cost[node][i]);
			ret.v = tmp.v;
		}
	}
	ret.v.push_back(node);
	return ret;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(m, 1, M) {
		int u, v, c;
		cin >> u >> v >> c;
		cost[u - 1][v - 1] = c;
	}
	NODE ans = DP(0, 1);
	if (ans.val == INF) {
		cout << -1;
	}
	else {
		cout << ans.val << "\n";
		ROF(i, LEN(ans.v) - 1, 0) {
			cout << ans.v[i] + 1 << " ";
		}
	}

	return 0;
}