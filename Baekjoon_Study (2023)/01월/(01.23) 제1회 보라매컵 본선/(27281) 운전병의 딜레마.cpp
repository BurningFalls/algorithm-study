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
#define MAX 50001

struct NODE {
	ll n;
	ll t;
	ll s;
};

ll N, M, T;
vector<vector<NODE>> Edge(MAX, vector<NODE>());

ll DT(int limit) {
	vector<ll> dist(N + 1, LINF);
	PQ<pll> pq;
	dist[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		ll node = pq.top().second;
		pq.pop();
		if (dist[node] >= T) continue;
		if (dist[node] < cost) continue;
		FOR(i, 0, LEN(Edge[node]) - 1) {
			ll next = Edge[node][i].n;
			ll ncost = cost + Edge[node][i].t + max(0LL, Edge[node][i].s - limit);
			if (ncost > T) continue;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
	return dist[N];
}

int main() {
	FASTIO;
	cin >> N >> M >> T;
	FOR(i, 1, M) {
		int u, v, t, s;
		cin >> u >> v >> t >> s;
		Edge[u].push_back({ v, t, s });
		Edge[v].push_back({ u, t, s });
	}

	ll left = 0, right = 1000000000;
	ll ans = LINF;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll result = DT(mid);
		if (result <= T) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << (ans == LINF ? -1 : ans);

	return 0;
}