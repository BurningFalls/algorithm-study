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
vector<vector<int>> Edge(MAX, vector<int>());
vector<vector<int>> Parent(MAX, vector<int>(18));
vector<int> depth(MAX);

void Travel(int node, int prev) {
	depth[node] = depth[prev] + 1;
	Parent[node][0] = prev;

	FOR(i, 1, max_dep) {
		Parent[node][i] = Parent[Parent[node][i - 1]][i - 1];
	}

	for (int next : Edge[node]) {
		if (next == prev) continue;
		Travel(next, node);
	}
}

int LCA(int x, int y) {
	if (depth[x] < depth[y]) {
		swap(x, y);
	}

	ROF(i, max_dep, 0) {
		if (depth[Parent[x][i]] >= depth[y]) {
			x = Parent[x][i];
		}
	}

	if (x == y) {
		return x;
	}

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
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}
	
	depth[0] = -1;
	Travel(1, 0);

	int M;
	cin >> M;
	FOR(i, 1, M) {
		int x, y;
		cin >> x >> y;
		cout << LCA(x, y) << "\n";
	}

	return 0;
}