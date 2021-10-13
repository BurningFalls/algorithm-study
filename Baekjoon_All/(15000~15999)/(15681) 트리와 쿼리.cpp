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
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int DFS(int node, int prev, vvi& edge, vi& ans) {
	int cnt = 1;
	for (int next : edge[node]) {
		if (prev == next) continue;
		cnt += DFS(next, node, edge, ans);
	}
	return ans[node] = cnt;
}

int main() {
	FASTIO;
	int N, R, Q;
	cin >> N >> R >> Q;
	vvi edge(N + 1);
	vi ans(N + 1, 0);
	FOR(i, 1, N - 1) {
		int U, V;
		cin >> U >> V;
		edge[U].push_back(V);
		edge[V].push_back(U);
	}
	DFS(R, 0, edge, ans);
	FOR(q, 1, Q) {
		int U;
		cin >> U;
		P1(ans[U]);
	}


	return 0;
}