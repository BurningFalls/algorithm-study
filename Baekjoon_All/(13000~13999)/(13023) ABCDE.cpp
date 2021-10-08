#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define ALL(v) v.begin(),v.end()

void DFS(int node, int depth, vector<vector<int>>& edge, vector<bool>& visited) {
	if (depth == 4) {
		cout << 1;
		exit(0);
	}
	vector<int> v;
	sort(ALL(v));
	visited[node] = 1;
	for (int next : edge[node]) {
		if (visited[next]) continue;
		DFS(next, depth + 1, edge, visited);
	}
	visited[node] = 0;
}

int main() {
	FASTIO;
	int N, M;
	vector<vector<int>> edge(2001);
	vector<bool> visited(2001, 0);
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	FOR(i, 0, N - 1) {
		DFS(i, 0, edge, visited);
	}
	cout << 0;

	return 0;
}