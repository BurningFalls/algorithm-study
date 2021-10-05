#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define INF 1000000000000000000
#define MOD 1000000009

struct NODE {
	ll dist;
	int cnt;
	int node;
};

struct compare {
	bool operator() (NODE& a, NODE& b) {
		if (a.dist == b.dist)
			return a.cnt > b.cnt;
		return a.dist > b.dist;
	}
};

ll dist[100001];
int cnt[100001];
vector<pii> edge[100001];
priority_queue<NODE, vector<NODE>, compare> pq;
int dp[100001] = { 0, };

void DT(int start) {
	dist[start] = 0;
	cnt[start] = 0;
	pq.push({ 0, 0, start });
	while (!pq.empty()) {
		ll cur_dist = pq.top().dist;
		int cur_cnt = pq.top().cnt;
		int cur_node = pq.top().node;
		pq.pop();
		if (dist[cur_node] < cur_dist)
			continue;
		FOR(i, 0, LEN(edge[cur_node]) - 1) {
			int next = edge[cur_node][i].first;
			ll ndist = edge[cur_node][i].second + cur_dist;
			int ncnt = cur_cnt + 1;
			if (dist[next] > ndist) {
				dist[next] = ndist;
				cnt[next] = ncnt;
				pq.push({ ndist, ncnt, next });
			}
			else if (dist[next] == ndist) {
				if (cnt[next] > ncnt) {
					cnt[next] = ncnt;
					pq.push({ ndist, ncnt, next });
				}
			}
		}
	}
}

int DP(int node) {
	int& ret = dp[node];
	if (ret != -1)
		return ret;
	ret = 0;
	FOR(i, 0, LEN(edge[node]) - 1) {
		int next = edge[node][i].first;
		int cost = edge[node][i].second;
		if (dist[node] + cost != dist[next]) continue;
		if (cnt[node] + 1 != cnt[next]) continue;
		ret = (ret + DP(next)) % MOD;
	}
	return ret;
}

int main() {
	FASTIO;
	MEMSET(dp, -1);
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	FOR(i, 1, N) {
		dist[i] = INF;
		cnt[i] = INF;
	}
	FOR(i, 1, M) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({ v, w });
	}
	DT(X);
	if (dist[Y] == INF) {
		cout << -1;
		return 0;
	}
	dp[Y] = 1;
	cout << dist[Y] << "\n" << cnt[Y] << "\n" << DP(X);

	return 0;
}