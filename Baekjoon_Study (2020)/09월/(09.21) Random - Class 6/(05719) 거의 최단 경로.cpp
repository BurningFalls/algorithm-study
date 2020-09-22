#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 987654321

int N, M;
int S, D;
vector<pair<int, int>> vec[501];
vector<pair<int, int>> trace[501];
int dist[501];

void DT() {
	priority_queue<pair<int, int>> pq;
	FOR(i, 0, N - 1)
		dist[i] = INF;
	pq.push({ 0, S });
	dist[S] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)
			continue;
		int len = vec[cur].size();
		FOR(i, 0, len - 1) {
			if (vec[cur][i].second == -1)
				continue;
			int next = vec[cur][i].first;
			int next_d = cost + vec[cur][i].second;
			if (dist[next] > next_d) {
				dist[next] = next_d;
				pq.push({ -next_d, next });
				trace[next].clear();
				trace[next].push_back({ cur, next_d });
			}
			else if (dist[next] == next_d)
				trace[next].push_back({ cur, next_d });
		}
	}
}

void BFS() {
	queue<int> q;
	q.push(D);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int len = trace[cur].size();
		FOR(i, 0, len - 1) {
			int next = trace[cur][i].first;
			int len2 = vec[next].size();
			FOR(j, 0, len2 - 1) {
				if (vec[next][j].first == cur)
					vec[next][j].second = -1;
			}
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		FOR(i, 0, N - 1) {
			trace[i].clear();
			vec[i].clear();
		}
		cin >> S >> D;
		FOR(i, 0, M - 1) {
			int u, v, p;
			cin >> u >> v >> p;
			vec[u].push_back({ v, p });
		}
		DT();
		BFS();
		DT();
		if (dist[D] == INF)
			cout << -1;
		else
			cout << dist[D];
		cout << "\n";
	}

	return 0;
}