#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int dp[101][10001];
vector<pair<int, pii>> V[101];

int DP(int pos, int cost, int goal, int limit_cost) {
	if (cost > limit_cost)
		return INF;
	if (pos == goal)
		return 0;
	int& ret = dp[pos][cost];
	if (ret != -1)
		return ret;
	ret = INF;
	int len = V[pos].size();
	FOR(i, 0, len - 1) {
		int next_pos = V[pos][i].first;
		int next_cost = V[pos][i].second.first;
		int next_time = V[pos][i].second.second;
		ret = min(ret, DP(next_pos, cost + next_cost, goal, limit_cost) + next_time);
	}
	return ret;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof(dp));
		int N, M, K;
		int u, v, c, d;
		cin >> N >> M >> K;
		if (N == 1) {
			cout << "0\n";
			continue;
		}
		if (K == 0) {
			cout << "Poor KCM\n";
			continue;
		}
		FOR(i, 1, N)
			V[i].clear();
		FOR(i, 1, K) {
			cin >> u >> v >> c >> d;
			V[u].push_back({ v, {c, d} });
		}
		int flag = DP(1, 0, N, M);
		if (flag == -1 || flag == INF)
			cout << "Poor KCM";
		else
			cout << flag;
		cout << "\n";
	}

	return 0;
}