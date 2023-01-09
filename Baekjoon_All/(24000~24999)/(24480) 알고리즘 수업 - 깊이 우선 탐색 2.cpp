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

int N, M, R;
vector<vector<int>> Edge(MAX, vector<int>());
vector<int> order(MAX, 0);
int cnt = 0;

void DFS(int node) {
	cnt++;
	order[node] = cnt;
	for (const int& next : Edge[node]) {
		if (order[next]) continue;
		DFS(next);
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> R;
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}
	FOR(i, 1, N) {
		sort(ALL(Edge[i]), greater<int>());
	}
	DFS(R);

	FOR(i, 1, N) {
		cout << order[i] << "\n";
	}

	return 0;
}