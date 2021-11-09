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

vector<vector<pii>> Edge(1001, vector<pii>());
vector<vector<int>> Dist(1001, vector<int>(1001));

void DFS(int node, int prev, int start, int sum) {
	Dist[start][node] = sum;
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		int dist = Edge[node][i].second;
		if (next == prev) continue;
		DFS(next, node, start, sum + dist);
	}
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge[a].push_back({ b, c });
		Edge[b].push_back({ a, c });
	}
	FOR(i, 1, N) {
		DFS(i, 0, i, 0);
	}
	FOR(m, 1, M) {
		int a, b;
		cin >> a >> b;
		cout << Dist[a][b] << "\n";
	}

	return 0;
}