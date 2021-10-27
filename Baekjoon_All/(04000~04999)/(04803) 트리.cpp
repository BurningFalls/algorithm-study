#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

bool DFS(int node, int prev, vvi& Edge, vi& visited) {
	if (visited[node]) {
		return false;
	}
	visited[node] = 1;
	bool flag = true;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		flag &= DFS(next, node, Edge, visited);
	}
	return flag;
}

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		vvi Edge(N + 1, vi());
		vi visited(N + 1, 0);
		FOR(m, 1, M) {
			int a, b;
			cin >> a >> b;
			Edge[a].push_back(b);
			Edge[b].push_back(a);
		}
		int tree_cnt = 0;
		FOR(i, 1, N) {
			if (visited[i]) continue;
			tree_cnt += DFS(i, 0, Edge, visited);
		}
		cout << "Case " << idx << ": ";
		if (tree_cnt == 0) {
			cout << "No trees.";
		}
		else if (tree_cnt == 1) {
			cout << "There is one tree.";
		}
		else {
			cout << "A forest of " << tree_cnt << " trees.";
		}
		cout << "\n";
		idx++;
	}

	return 0;
}