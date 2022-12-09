#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 40001

int N;
int max_dep;
vector<vector<pll>> Edge(MAX, vector<pll>());
vector<vector<int>> Parent(MAX, vector<int>(17));
vector<int> depth(MAX);
vector<ll> dist(MAX);

void DFS(int node, int prev) {
	depth[node] = depth[prev] + 1;
	Parent[node][0] = prev;

	FOR(i, 1, max_dep) {
		Parent[node][i] = Parent[Parent[node][i - 1]][i - 1];
	}

	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		ll cost = Edge[node][i].second;
		if (next == prev) continue;
		dist[next] = dist[node] + cost;
		DFS(next, node);
	}
}

int LCA(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);

	ROF(i, max_dep, 0) {
		if (depth[Parent[x][i]] >= depth[y]) {
			x = Parent[x][i];
		}
	}

	if (x == y) return x;

	ROF(i, max_dep, 0) {
		if (Parent[x][i] != Parent[y][i]) {
			x = Parent[x][i];
			y = Parent[y][i];
		}
	}

	return Parent[x][0];
}

int main() {
	FASTIO;
	cin >> N;
	max_dep = (int)floor(log2(MAX));
	FOR(i, 1, N - 1) {
		int a, b; ll c;
		cin >> a >> b >> c;
		Edge[a].push_back({ b, c });
		Edge[b].push_back({ a, c });
	}

	depth[0] = -1;
	dist[1] = 0;
	DFS(1, 0);

	int M;
	cin >> M;
	FOR(i, 1, M) {
		int x, y;
		cin >> x >> y;
		int lca = LCA(x, y);
		cout << dist[x] + dist[y] - 2 * dist[lca] << "\n";
	}

	return 0;
}