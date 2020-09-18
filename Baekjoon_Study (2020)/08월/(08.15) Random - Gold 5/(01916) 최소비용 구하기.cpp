#include <bits/stdc++.h>
using namespace std;

#define INF 2100000000
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
vector<pair<int, int>> vt[1001];
int dist[1001];

void DT(int s) {
	priority_queue<pair<int, int>> pq;
	dist[s] = 0;
	pq.push(make_pair(-dist[s], s));
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
	int start, end;
	cin >> N >> M;
	FOR(i, 1, N)
		dist[i] = INF;
	FOR(i, 1, M) {
		int u, v, w;
		cin >> u >> v >> w;
		vt[u].push_back(make_pair(v, w));
	}
	cin >> start >> end;
	DT(start);
	cout << dist[end];

	return 0;
}