#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, M;
int S, D;
vector<pii> edge[501];
int dist[501];
vector<int> trace[501];
bool visited[501][501];

void DT() {
	FOR(i, 0, N - 1) {
		dist[i] = INF;
		trace[i].clear();
	}
	priority_queue<pii> pq;
	pq.push({ 0, S });
	dist[S] = 0;
	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		if (dist[cur_node] < cur_cost)
			continue;
		int len = edge[cur_node].size();
		FOR(i, 0, len - 1) {
			if (edge[cur_node][i].second == -1)
				continue;
			int next_node = edge[cur_node][i].first;
			int next_cost = edge[cur_node][i].second + cur_cost;
			if (dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				pq.push({ -dist[next_node], next_node });
				trace[next_node].clear();
				trace[next_node].push_back(cur_node);
			}
			else if (dist[next_node] == next_cost) {
				trace[next_node].push_back(cur_node);
			}
		}
	}
}

void Erase_Edge(int cur) {
	int len = trace[cur].size();
	FOR(i, 0, len - 1) {
		int next = trace[cur][i];
		if (visited[cur][next]) continue;
		if (visited[next][cur]) continue;
		visited[next][cur] = 1;
		visited[cur][next] = 1;
		int edge_len = edge[next].size();
		FOR(j, 0, edge_len - 1) {
			int tmp = edge[next][j].first;
			if (tmp == cur)
				edge[next][j].second = -1;
		}
		Erase_Edge(next);
	}
}

int main() {
	FASTIO;
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		cin >> S >> D;
		memset(visited, 0, sizeof(visited));
		FOR(i, 0, N - 1)
			edge[i].clear();
		FOR(i, 1, M) {
			int U, V, P;
			cin >> U >> V >> P;
			edge[U].push_back({ V, P });
		}
		DT();
		Erase_Edge(D);
		DT();
		if (dist[D] == INF)
			cout << -1;
		else
			cout << dist[D];
		cout << "\n";
	}


	return 0;
}