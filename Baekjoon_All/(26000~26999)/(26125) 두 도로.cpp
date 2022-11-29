#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 301

int N, M, S, T;
vector<vector<ll>> dist(MAX, vector<ll>(MAX, LINF));

int main() {
	FASTIO;
	cin >> N >> M >> S >> T;
	FOR(i, 1, M) {
		int u, v; ll w;
		cin >> u >> v >> w;
		dist[u][v] = min(dist[u][v], w);
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	FOR(i, 1, N) {
		dist[i][i] = 0;
	}
	int Q;
	cin >> Q;
	FOR(q, 1, Q) {
		int a1, b1, a2, b2; ll c1, c2;
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		ll ans = LINF;
		ans = min(ans, dist[S][T]);
		ans = min(ans, dist[S][a1] + c1 + dist[b1][T]);
		ans = min(ans, dist[S][a2] + c2 + dist[b2][T]);
		ans = min(ans, dist[S][a1] + c1 + dist[b1][a2] + c2 + dist[b2][T]);
		ans = min(ans, dist[S][a2] + c2 + dist[b2][a1] + c1 + dist[b1][T]);
		cout << (ans >= LINF ? -1 : ans) << "\n";
	}

	return 0;
}