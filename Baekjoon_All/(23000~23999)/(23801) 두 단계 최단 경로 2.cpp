#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 100001

int N;
vector<vector<pll>> Edge(MAX, vector<pll>());
vector<vector<ll>> Dist(2, vector<ll>(MAX, LINF));

void DT(int start, int idx) {
	PQ<pll> pq;
	pq.push({ 0, start });
	Dist[idx][start] = 0;
	while (!pq.empty()) {
		ll dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (Dist[idx][node] < dist) continue;
		FOR(i, 0, LEN(Edge[node]) - 1) {
			int next = Edge[node][i].first;
			ll ndist = Edge[node][i].second;
			if (Dist[idx][next] > dist + ndist) {
				Dist[idx][next] = dist + ndist;
				pq.push({ -Dist[idx][next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	int M, X, Z, P;
	cin >> N >> M;
	FOR(m, 1, M) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		Edge[u].push_back({ v, w });
		Edge[v].push_back({ u, w });
	}
	cin >> X >> Z;

	DT(X, 0);
	DT(Z, 1);

	ll ans = LINF;
	cin >> P;
	FOR(p, 1, P) {
		int Y;
		cin >> Y;
		if (Dist[0][Y] == LINF || Dist[1][Y] == LINF) continue;
		ans = min(ans, Dist[0][Y] + Dist[1][Y]);
	}
	cout << (ans == LINF ? -1 : ans);

	return 0;
}