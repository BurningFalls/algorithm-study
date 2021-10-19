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

int N, R1, R2;
vector<vector<pii>> Edge(100001, vector<pii>());
vector<int> Vertex;

void DFS(int node, int prev) {
	if (node == R2) {
		sort(ALL(Vertex));
		int sum = 0;
		FOR(i, 0, LEN(Vertex) - 2) {
			sum += Vertex[i];
		}
		cout << sum;
		exit(0);
	}
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		int dist = Edge[node][i].second;
		if (next == prev) continue;
		Vertex.push_back(dist);
		DFS(next, node);
		Vertex.pop_back();
	}
}

int main() {
	FASTIO;
	cin >> N >> R1 >> R2;
	FOR(i, 1, N - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge[a].push_back({ b, c });
		Edge[b].push_back({ a, c });
	}
	DFS(R1, 0);


	return 0;
}