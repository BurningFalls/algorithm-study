#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, E;
vector<pair<int, int>> v[801];

int DFS(int start, int end) {
	int dist[801];
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
		int len = v[n].size();
		FOR(i, 0, len - 1) {
			int nn = v[n][i].first;
			int nd = v[n][i].second + d;
			if (dist[nn] > nd) {
				dist[nn] = nd;
				pq.push({ -dist[nn], nn });
			}
		}
	}
	return dist[end];
}

int main() {
	FASTIO;
	int v1, v2;
	cin >> N >> E;
	FOR(i, 1, E) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;
	if (DFS(v1, v2) == INF)
		cout << -1;
	else {
		int temp1 = DFS(v1, v2);
		int ans1, ans2;
		ans1 = DFS(1, v1) + temp1 + DFS(v2, N);
		ans2 = DFS(1, v2) + temp1 + DFS(v1, N);
		if (ans1 >= INF && ans2 >= INF)
			cout << -1;
		else
			cout << min(ans1, ans2);
	}

	return 0;
}