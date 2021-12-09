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
vector<vector<ll>> Dist(101, vector<ll>(MAX, LINF));

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
		int u, v, w;
		cin >> u >> v >> w;
		Edge[u].push_back({ v, w });
		Edge[v].push_back({ u, w });
	}
	cin >> X >> Z;
	cin >> P;

	DT(X, 0);

	vector<int> Y(P + 1);
	FOR(i, 1, P) {
		cin >> Y[i];
		DT(Y[i], i);
	}

	ll ans = LINF;
	FOR(i, 1, P) {
		FOR(j, 1, P) {
			if (j == i) continue;
			FOR(k, 1, P) {
				if (k == i || k == j) continue;
				if (Dist[0][Y[i]] == LINF || Dist[i][Y[j]] == LINF || Dist[j][Y[k]] == LINF || Dist[k][Z] == LINF) continue;
				ans = min(ans, Dist[0][Y[i]] + Dist[i][Y[j]] + Dist[j][Y[k]] + Dist[k][Z]);
			}
		}
	}
	cout << (ans == LINF ? -1 : ans);

	return 0;
}