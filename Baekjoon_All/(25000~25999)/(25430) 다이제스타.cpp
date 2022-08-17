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
	int node;
	ll cost;
	ll prev;
};

int N, M;
int S, E;
vector<vector<pll>> Edge(MAX, vector<pll>());
vector<ll> dist(MAX, LINF);

bool compare(pll a, pll b) {
	return a.second > b.second;
}

void DT() {
	queue<NODE> q;
	q.push({ S, 0, 0 });
	dist[S] = 0;
	while (!q.empty()) {
		int cur = q.front().node;
		ll cost = q.front().cost;
		ll prev = q.front().prev;
		q.pop();
		FOR(i, 0, LEN(Edge[cur]) - 1) {
			int next = Edge[cur][i].first;
			ll ncost = Edge[cur][i].second;
			if (ncost <= prev) break;
			dist[next] = min(dist[next], ncost + cost);
			q.push({ next, ncost + cost, ncost });
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int u, v, w;
		cin >> u >> v >> w;
		Edge[u].push_back({ v, w });
		Edge[v].push_back({ u, w });
	}
	cin >> S >> E;
	FOR(i, 1, N) {
		sort(ALL(Edge[i]), compare);
	}
	DT();

	if (dist[E] == LINF) {
		cout << "DIGESTA";
	}
	else {
		cout << dist[E];
	}

	return 0;
}