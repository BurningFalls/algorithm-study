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

vector<int> C(200001);
vector<vector<int>> Edge(200001, vector<int>());

int DFS(int node, int prev) {
	int cnt = 0;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		cnt += DFS(next, node) + (C[node] != C[next]);
	}
	return cnt;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> C[i];
	}
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	int ans = DFS(1, 0);
	if (C[1] != 0) {
		ans++;
	}
	cout << ans;

	return 0;
}