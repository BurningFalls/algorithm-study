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

int DFS(int node, int prev, int N, vector<vector<pii>>& Edge) {
	int sum = 0;
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		int cost = Edge[node][i].second;
		if (next == prev) continue;
		sum += min(DFS(next, node, N, Edge), cost);
	}
	return (sum == 0 ? INF : sum);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<pii>> Edge(N + 1, vector<pii>());
		FOR(m, 1, M) {
			int a, b, c;
			cin >> a >> b >> c;
			Edge[a].push_back({ b, c });
			Edge[b].push_back({ a, c });
		}
		int ans = DFS(1, 0, N, Edge);
		cout << (ans == INF ? 0 : ans) << "\n";
	}

	return 0;
}