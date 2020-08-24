#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M, X;
vector<pair<int, int>> v[1001];

int DT(int start, int end) {
	int dist[1001];
	FOR(i, 1, N)
		dist[i] = INF;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int n = pq.top().second;
		pq.pop();
		if (dist[n] < d)
			continue;
		int size = v[n].size();
		FOR(i, 0, size - 1) {
			int nn = v[n][i].first;
			int nd = v[n][i].second + d;
			if (dist[nn] > nd) {
				dist[nn] = nd;
				pq.push(make_pair(-nd, nn));
			}
		}
	}
	return dist[end];
}

int main() {
	FASTIO;
	int ans = 0;
	cin >> N >> M >> X;
	FOR(i, 1, M) {
		int a, b, t;
		cin >> a >> b >> t;
		v[a].push_back(make_pair(b, t));
	}
	FOR(i, 1, N) {
		int temp1 = DT(i, X);
		int temp2 = DT(X, i);
		if (temp1 == INF || temp2 == INF) continue;
		ans = max(ans, temp1 + temp2);
	}
	cout << ans;

	return 0;
}