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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int N, M, K;
vector<vector<pll>> edge(10001);
vector<vector<ll>> dist(10001, vector<ll>(21, LINF));
PQ<pair<ll, pll>> pq;

void DT() {
	pq.push({ 0, {1, 0} });
	dist[1][0] = 0;
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int node = pq.top().second.first;
		int cnt = pq.top().second.second;
		pq.pop();
		if (dist[node][cnt] < cost) continue;
		FOR(i, 0, LEN(edge[node]) - 1) {
			int next = edge[node][i].first;
			ll ncost = edge[node][i].second + cost;
			if (dist[next][cnt] > ncost) {
				dist[next][cnt] = ncost;
				pq.push({ -ncost, { next, cnt} });
			}
			if (cnt == K) continue;
			if (dist[next][cnt + 1] > cost) {
				dist[next][cnt + 1] = cost;
				pq.push({ -cost, {next, cnt + 1} });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	DT();
	ll mini = LINF;
	FOR(i, 0, K) {
		mini = min(mini, dist[N][i]);
	}
	P1(mini);

	return 0;
}