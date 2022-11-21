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
#define MAX 30001

ll M, N, K, S, E;
vector<vector<pll>> Edge(MAX, vector<pll>());
vector<map<ll, set<ll>>> Forb(MAX, map<ll, set<ll>>());
vector<map<ll, ll>> dist(MAX, map<ll, ll>());

void DT() {
	PQ<pair<ll, pll>> pq;
	pq.push({ 0, {S, 0} });
	dist[S][0] = 0;
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		ll node = pq.top().second.first;
		ll prev = pq.top().second.second;
		pq.pop();
		FOR(i, 0, LEN(Edge[node]) - 1) {
			ll next = Edge[node][i].first;
			ll ncost = Edge[node][i].second + cost;
			if (Forb[node].count(prev) && Forb[node][prev].count(next)) continue;
			if (dist[next].count(node)) {
				if (dist[next][node] > ncost) {
					dist[next][node] = ncost;
					pq.push({ -dist[next][node], {next, node} });
				}
			}
			else {
				dist[next][node] = ncost;
				pq.push({ -dist[next][node], {next, node} });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> M >> N >> K;
	cin >> S >> E;
	S += 1; E += 1;
	FOR(m, 1, M) {
		ll x, y, c;
		cin >> x >> y >> c;
		Edge[x + 1].push_back({ y + 1, c });
	}
	FOR(k, 1, K) {
		ll x, y, z;
		cin >> x >> y >> z;
		Forb[y + 1][x + 1].insert(z + 1);
	}

	DT();

	ll ans = LINF;
	for (auto it = dist[E].begin(); it != dist[E].end(); it++) {
		ans = min(ans, (*it).second);
	}
	cout << (ans == LINF ? -1 : ans);

	return 0;
}