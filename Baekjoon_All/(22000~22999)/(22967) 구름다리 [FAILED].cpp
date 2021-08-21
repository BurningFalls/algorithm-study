#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
vector<int> edge[301];
int depth[301];
bool visited[301] = { 0, };
int connected[301] = { 0, };
vector<int> leaf_v;
int far1, far2;

void DFS(int node, int d) {
	for (int next : edge[node]) {
		if (visited[next]) continue;
		visited[next] = 1;
		depth[next] = d + 1;
		DFS(next, d + 1);
		visited[next] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		connected[u]++;
		connected[v]++;
	}
	if (N == 2) {
		cout << 0 << "\n" << 1;
		return 0;
	}
	depth[1] = 0;
	visited[1] = 1;
	DFS(1, 0);

	int max_depth = 0;
	FOR(i, 1, N)
		max_depth = max(max_depth, depth[i]);
	FOR(i, 1, N) {
		if (depth[i] == max_depth)
			far1 = i;
	}
	memset(visited, 0, sizeof(visited));
	DFS(far1, 0);
	max_depth = 0;
	FOR(i, 1, N)
		max_depth = max(max_depth, depth[i]);
	FOR(i, 1, N) {
		if (depth[i] == max_depth)
			far2 = i;
	}
	int diameter = depth[far2];
	diameter = (diameter + 1) / 2;
	FOR(i, 1, N) {
		if (connected[i] == 1)
			leaf_v.push_back(i);
	}
	int leaf_cnt = leaf_v.size();
	cout << leaf_cnt << "\n";
	cout << diameter << "\n";
	FOR(i, 0, leaf_cnt - 1) {
		cout << leaf_v[i] << " " << leaf_v[(i + 1) % leaf_cnt] << "\n";
	}


	return 0;
}