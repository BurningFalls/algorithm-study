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
#define MAX 100001

int N;
vector<vector<pii>> Edge(MAX, vector<pii>());
vector<int> Dist(MAX, INF);

int DT(int start, int end, int dont) {
	PQ<pii> pq;
	fill(ALL(Dist), INF);
	Dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (Dist[node] < dist) continue;
		FOR(i, 0, LEN(Edge[node]) - 1) {
			int next = Edge[node][i].first;
			int ndist = Edge[node][i].second;
			if (next == dont) continue;
			if (Dist[next] > dist + ndist) {
				Dist[next] = dist + ndist;
				pq.push({ -Dist[next], next });
			}
		}
	}
	return Dist[end];
}

int main() {
	FASTIO;
	int M, X, Y, Z;
	cin >> N >> M;
	FOR(m, 1, M) {
		int u, v, w;
		cin >> u >> v >> w;
		Edge[u].push_back({ v, w });
	}
	cin >> X >> Y >> Z;
	int xy_dist = DT(X, Y, 0);
	int yz_dist = DT(Y, Z, 0);
	int noty_dist = DT(X, Z, Y);
	cout << (xy_dist == INF || yz_dist == INF ? -1 : xy_dist + yz_dist) << " ";
	cout << (noty_dist == INF ? -1 : noty_dist);

	return 0;
}