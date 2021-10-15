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

void DFS(int node, int prev, int depth, vvi& Child, vi& Depth) {
	Depth[node] = depth;
	for (int next : Child[node]) {
		if (prev == next) continue;
		DFS(next, node, depth + 1, Child, Depth);
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vi Parent(N + 1, 0);
		vvi Child(N + 1);
		vi Depth(N + 1, 0);
		FOR(i, 1, N - 1) {
			int a, b;
			cin >> a >> b;
			Parent[b] = a;
			Child[a].push_back(b);
		}
		int root = 0;
		FOR(i, 1, N) {
			if (Parent[i] == 0) {
				root = i;
			}
		}
		DFS(root, 0, 0, Child, Depth);
		int n1, n2;
		cin >> n1 >> n2;
		if (Depth[n1] > Depth[n2]) {
			int cnt = Depth[n1] - Depth[n2];
			FOR(i, 1, cnt) {
				n1 = Parent[n1];
			}
		}
		else if (Depth[n1] < Depth[n2]) {
			int cnt = Depth[n2] - Depth[n1];
			FOR(i, 1, cnt) {
				n2 = Parent[n2];
			}
		}
		while (n1 != n2) {
			n1 = Parent[n1];
			n2 = Parent[n2];
		}
		P1(n1);
	}

	return 0;
}