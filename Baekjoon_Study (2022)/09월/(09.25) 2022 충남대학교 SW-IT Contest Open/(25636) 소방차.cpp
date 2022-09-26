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
#define MAX 100001

struct NODE {
	ll node;
	ll dist;
	ll water;

	bool operator<(const NODE& n) const {
		return dist > n.dist;
	}
};

int N, M, S, T;
vector<ll> A(MAX);
vector<vector<pll>> Edge(MAX, vector<pll>());
vector<ll> dist(MAX, LINF);
vector<ll> tank(MAX, 0);

void DT() {
	PQ<NODE> pq;
	dist[S] = 0;
	tank[S] = A[S];
	pq.push({ S, dist[S], tank[S] });
	while (!pq.empty()) {
		ll node = pq.top().node;
		ll cost = pq.top().dist;
		ll water = pq.top().water;
		pq.pop();
		if (dist[node] < cost) continue;
		FOR(i, 0, LEN(Edge[node]) - 1) {
			ll next = Edge[node][i].first;
			ll ndist = Edge[node][i].second + cost;
			ll nwater = A[next] + water;
			if (dist[next] > ndist) {
				dist[next] = ndist;
				tank[next] = nwater;
				pq.push({ next, dist[next], tank[next] });
			}
			else if (dist[next] == ndist) {
				if (tank[next] < nwater) {
					tank[next] = nwater;
					pq.push({ next, dist[next], tank[next] });
				}
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	cin >> M;
	FOR(i, 1, M) {
		ll u, v, w;
		cin >> u >> v >> w;
		Edge[u].push_back({ v, w });
		Edge[v].push_back({ u, w });
	}
	cin >> S >> T;

	DT();

	if (dist[T] == LINF) {
		cout << -1;
	}
	else {
		cout << dist[T] << " " << tank[T];
	}

	return 0;
}