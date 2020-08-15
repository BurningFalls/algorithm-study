#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int V, E, K;
vector<pair<int, int>> vt[20001];
int dist[20001];

void DT() {
	priority_queue<pair<int, int>> pq;
	dist[K] = 0;
	pq.push(make_pair(-dist[K], K));
	while (!pq.empty()) {
		int nd = -pq.top().first;
		int n = pq.top().second;
		pq.pop();
		if (dist[n] < nd)
			continue;
		int len = vt[n].size();
		FOR(i, 0, len - 1) {
			int nn = vt[n][i].first;
			int nnd = nd + vt[n][i].second;
			if (dist[nn] > nnd) {
				dist[nn] = nnd;
				pq.push(make_pair(-nnd, nn));
			}
		}
	}
}

int main() {
	cin >> V >> E;
	cin >> K;
	FOR(i, 1, V)
		dist[i] = INF;
	FOR(i, 1, E) {
		int u, v, w;
		cin >> u >> v >> w;
		vt[u].push_back(make_pair(v, w));
	}
	DT();
	FOR(i, 1, V) {
		if (dist[i] == INF)
			cout << "INF";
		else
			cout << dist[i];
		cout << "\n";
	}

	return 0;
}