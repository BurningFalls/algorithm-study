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
#define MAX 100001

int N;
int max_dep;
vector<vector<pii>> Edge(MAX, vector<pii>());
vector<vector<int>> Parent(MAX, vector<int>(18));
vector<int> depth(MAX);
vector<vector<int>> min_dist(MAX, vector<int>(18));
vector<vector<int>> max_dist(MAX, vector<int>(18));
int mini, maxi;

void DFS(int node, int prev, int dist) {
	depth[node] = depth[prev] + 1;
	Parent[node][0] = prev;
	min_dist[node][0] = dist;
	max_dist[node][0] = dist;

	FOR(i, 1, max_dep) {
		Parent[node][i] = Parent[Parent[node][i - 1]][i - 1];
		min_dist[node][i] = min(min_dist[node][i - 1], min_dist[Parent[node][i - 1]][i - 1]);
		max_dist[node][i] = max(max_dist[node][i - 1], max_dist[Parent[node][i - 1]][i - 1]);
	}

	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		int cost = Edge[node][i].second;
		if (next == prev) continue;
		DFS(next, node, cost);
	}
}

void LCA(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);

	ROF(i, max_dep, 0) {
		if (depth[Parent[x][i]] >= depth[y]) {
			mini = min(mini, min_dist[x][i]);
			maxi = max(maxi, max_dist[x][i]);
			x = Parent[x][i];
		}
	}

	if (x == y) return;

	ROF(i, max_dep, 0) {
		if (Parent[x][i] != Parent[y][i]) {
			mini = min({ mini, min_dist[x][i], min_dist[y][i] });
			maxi = max({ maxi, max_dist[x][i], max_dist[y][i] });
			x = Parent[x][i];
			y = Parent[y][i];
		}
	}

	if (x != Parent[x][0]) {
		mini = min({ mini, min_dist[x][0], min_dist[y][0] });
		maxi = max({ maxi, max_dist[x][0], max_dist[y][0] });
	}
}

int main() {
	FASTIO;
	cin >> N;
	max_dep = (int)floor(log2(MAX));
	FOR(i, 1, N - 1) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge[A].push_back({ B, C });
		Edge[B].push_back({ A, C });
	}

	depth[0] = -1;
	DFS(1, 0, 0);

	int K;
	cin >> K;
	FOR(i, 1, K) {
		int D, E;
		cin >> D >> E;
		mini = INF;
		maxi = -1;
		LCA(D, E);
		cout << mini << " " << maxi << "\n";
	}

	return 0;
}