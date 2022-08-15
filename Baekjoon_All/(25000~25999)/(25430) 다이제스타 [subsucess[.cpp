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

int N, M;
int S, E;
vector<vector<pll>> Edge(MAX, vector<pll>());
vector<ll> dist(MAX, LINF);

bool compare(pll a, pll b) {
	return a.second < b.second;
}

int Find(int cur, int prev) {
	int ans = LEN(Edge[cur]);
	int left = 0, right = LEN(Edge[cur]) - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (Edge[cur][mid].second > prev) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}

void DT() {
	PQ<pair<ll, pll>> pq;
	pq.push({ 0, {S, 0} });
	dist[S] = 0;
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int cur = pq.top().second.first;
		int prev = pq.top().second.second;
		pq.pop();
		if (dist[cur] < cost) continue;
		int idx = Find(cur, prev);
		FOR(i, idx, LEN(Edge[cur]) - 1) {
			int next = Edge[cur][i].first;
			ll ncost = Edge[cur][i].second;
			if (dist[next] > ncost + cost) {
				dist[next] = ncost + cost;
				pq.push({ -dist[next], {next, ncost} });
			}
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