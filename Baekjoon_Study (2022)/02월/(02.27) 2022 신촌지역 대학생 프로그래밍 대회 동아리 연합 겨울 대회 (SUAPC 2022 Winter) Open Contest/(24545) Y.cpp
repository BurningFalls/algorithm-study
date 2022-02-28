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

int N;
vector<vector<int>> Edge(MAX, vector<int>());
int v[2] = { 0, 0 };
int max_dist = -1;
vector<int> route(MAX, 0);
vector<bool> visited(MAX, 0);

void DFS(int node, int prev, int dist, int idx) {
	if (max_dist < dist) {
		max_dist = dist;
		v[idx] = node;
	}
	for (int next : Edge[node]) {
		if (next == prev) continue;
		DFS(next, node, dist + 1, idx);
	}
}

bool Routing(int node, int goal, int prev, int dist) {
	route[dist] = node;
	if (node == goal) {
		return true;
	}
	bool flag = false;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		flag |= Routing(next, goal, node, dist + 1);
		if (flag) break;
	}
	return flag;
}

int DFS2(int node) {
	int maxi = 0;
	for (int next : Edge[node]) {
		if (visited[next]) continue;
		visited[next] = 1;
		maxi = max(maxi, DFS2(next));
	}
	return maxi + 1;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}
	DFS(1, 0, 0, 0);
	max_dist = -1;
	DFS(v[0], 0, 0, 1);
	Routing(v[0], v[1], 0, 0);

	FOR(i, 0, max_dist) {
		visited[route[i]] = 1;
	}
	int maxi = 1;
	FOR(i, 1, max_dist - 1) {
		maxi = max(maxi, DFS2(route[i]));
	}
	cout << (maxi == 1 ? 0 : max_dist + maxi);

	return 0;
}