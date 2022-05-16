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
int S, C, H;
vector<vector<int>> Edge(MAX, vector<int>());
vector<bool> visited(MAX, 0);
vector<int> depth(MAX, -1);
vector<int> Parent(MAX, 0);

void BFS(int start) {
	queue<int> q;
	visited[start] = 1;
	depth[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int next : Edge[node]) {
			if (visited[next]) continue;
			visited[next] = 1;
			depth[next] = depth[node] + 1;
			Parent[next] = node;
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	cin >> S >> C >> H;
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}

	BFS(S);

	int cnode = C;
	int hnode = H;
	int Cdepth = depth[C];
	int Hdepth = depth[H];
	ll cmove = 0;
	ll hmove = 0;

	if (Cdepth > Hdepth) {
		while (Cdepth > Hdepth) {
			cmove++;
			cnode = Parent[cnode];
			Cdepth--;
		}
	}
	else if (Cdepth < Hdepth) {
		while (Cdepth < Hdepth) {
			hmove++;
			hnode = Parent[hnode];
			Hdepth--;
		}
	}
	while (cnode != hnode) {
		cmove++;
		hmove++;
		cnode = Parent[cnode];
		hnode = Parent[hnode];
	}

	ll SC_dist = depth[C];
	ll CH_dist = cmove + hmove;

	ll total = SC_dist + CH_dist + 1;
	total = total * (total - 1) / 2;
	ll minus = (SC_dist + hmove) * cmove;
	cout << total - minus;

	return 0;
}