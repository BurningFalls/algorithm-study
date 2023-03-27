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

int N, M, K;
vector<vector<pll>> Edge(MAX, vector<pll>());
vector<ll> dist(MAX, LINF);
PQ<pll> pq;

void DT() {
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;
		FOR(i, 0, LEN(Edge[node]) - 1) {
			int next = Edge[node][i].first;
			ll ncost = Edge[node][i].second + cost;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, M) {
		ll a, b, c;
		cin >> a >> b >> c;
		Edge[b].push_back({ a, c });
	}
	FOR(i, 1, K) {
		int x;
		cin >> x;
		dist[x] = 0;
		pq.push({ 0, x });
	}
	DT();

	ll maxi = 0;
	int max_idx = 1;
	FOR(i, 1, N) {
		if (maxi < dist[i]) {
			maxi = dist[i];
			max_idx = i;
		}
	}
	cout << max_idx << "\n" << maxi;

	return 0;
}