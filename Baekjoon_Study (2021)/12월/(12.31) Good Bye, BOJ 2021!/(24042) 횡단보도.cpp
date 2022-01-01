#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int N, M;
vector<vector<pll>> Edge(100001, vector<pll>());
PQ<pll> pq;
vector<ll> Dist(100001, LINF);

void DT() {
	pq.push({ 0, 1 });
	Dist[1] = 0;
	while (!pq.empty()) {
		ll cdist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		FOR(i, 0, LEN(Edge[node]) - 1) {
			int next = Edge[node][i].first;
			ll ndist = Edge[node][i].second;
			if (ndist < cdist) {
				ll tmp = (cdist - ndist) / M;
				if ((cdist - ndist) % M != 0) {
					tmp++;
				}
				ndist += M * tmp;
			}
			if (Dist[next] > ndist) {
				Dist[next] = ndist;
				pq.push({ -Dist[next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(m, 1, M) {
		ll a, b;
		cin >> a >> b;
		Edge[a].push_back({ b, m });
		Edge[b].push_back({ a, m });
	}
	DT();
	cout << Dist[N];

	return 0;
}