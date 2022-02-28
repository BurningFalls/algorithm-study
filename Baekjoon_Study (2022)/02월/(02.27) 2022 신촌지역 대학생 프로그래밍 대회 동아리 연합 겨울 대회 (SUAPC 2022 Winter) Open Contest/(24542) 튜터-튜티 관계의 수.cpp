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
#define MAX 200001
#define MOD 1000000007

vector<bool> visited(MAX, 0);
vector<vector<int>> Edge(MAX, vector<int>());

ll DFS(int node) {
	ll cnt = 1;
	for (int next : Edge[node]) {
		if (visited[next]) continue;
		visited[next] = 1;
		cnt += DFS(next);
	}
	return cnt;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(m, 1, M) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}
	ll ans = 1;
	FOR(i, 1, N) {
		if (visited[i]) continue;
		visited[i] = 1;
		ans = (ans * DFS(i)) % MOD;
	}
	cout << ans;

	return 0;
}