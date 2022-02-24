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

int N, M;
vector<vector<int>> Edge(18, vector<int>());
vector<vector<int>> cost(18, vector<int>(18, 0));
vector<vector<int>> dp(18, vector<int>(1 << 18, -1));
vector<int> route(18, -1);
int ans;

int DP(int node, int bm) {
	if (bm == (1 << N) - 1) {
		return dp[node][bm] = (cost[node][0] == 0 ? INF : cost[node][0]);
	}
	int& ret = dp[node][bm];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	for (int next : Edge[node]) {
		if (bm & (1 << next)) continue;
		int tmp = DP(next, bm | (1 << next));
		ret = min(ret, max(tmp, cost[node][next]));
	}
	return ret;
}

void BT(int node, int bm, int depth) {
	route[depth] = node;
	if (bm == (1 << N) - 1) {
		if (cost[node][0] != 0) {
			cout << ans << "\n";
			FOR(i, 0, N - 1) {
				cout << route[i] + 1 << " ";
			}
			exit(0);
		}
		return;
	}
	for (int next : Edge[node]) {
		if (bm & (1 << next)) continue;
		if (dp[node][bm] == max(dp[next][bm | (1 << next)], cost[node][next])) {
			BT(next, bm | (1 << next), depth + 1);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(m, 1, M) {
		int u, v, c;
		cin >> u >> v >> c;
		Edge[u - 1].push_back(v - 1);
		cost[u - 1][v - 1] = c;
	}
	ans = DP(0, 1);
	BT(0, 1, 0);
	cout << -1;

	return 0;
}