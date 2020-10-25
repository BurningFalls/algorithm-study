#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N;
int Map[126][126];
vector<pii> v[125 * 125 + 1];
int dist[125 * 125 + 1];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void DT() {
	priority_queue<pii> pq;
	pq.push({ -Map[1][1], 1 });
	dist[1] = Map[1][1];
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > dist[cur])
			continue;
		int len = v[cur].size();
		FOR(i, 0, len - 1) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (dist[next] > dist[cur] + ncost) {
				dist[next] = dist[cur] + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	int tc = 1;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		FOR(i, 1, N * N) {
			v[i].clear();
			dist[i] = INF;
		}
		FOR(i, 1, N) FOR(j, 1, N)
			cin >> Map[i][j];
		FOR(i, 1, N) FOR(j, 1, N) {
			int cur = N * (i - 1) + j;
			FOR(k, 0, 3) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
				int next = N * (ny - 1) + nx;
				v[cur].push_back({ next, Map[ny][nx] });
			}
		}
		DT();
		cout << "Problem " << tc << ": ";
		cout << dist[N * N] << "\n";
		tc++;
	}

	return 0;
}
