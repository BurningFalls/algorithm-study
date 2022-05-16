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
#define MAX 100001

int N, M, Q;
vector<int> kind(MAX);
vector<vector<int>> Edge(MAX, vector<int>());
vector<int> group_idx(MAX, 0);
vector<int> group_cnt(MAX, 0);
vector<int> group_clean(MAX, 0);

int DFS(int node, int gidx) {
	group_clean[gidx] += kind[node];
	int cnt = 1;
	for (int next : Edge[node]) {
		if (group_idx[next]) continue;
		group_idx[next] = gidx;
		cnt += DFS(next, gidx);
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> M >> Q;
	FOR(i, 1, N) {
		cin >> kind[i];
	}
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}

	int gidx = 0;
	FOR(i, 1, N) {
		if (group_idx[i]) continue;
		gidx++;
		group_idx[i] = gidx;
		int cnt = DFS(i, gidx);
		group_cnt[gidx] = cnt;
	}

	FOR(i, 1, Q) {
		int q;
		cin >> q;
		int total = group_cnt[group_idx[q]];
		int clean = group_clean[group_idx[q]];
		cout << (clean > total - clean) << "\n";
	}

	return 0;
}