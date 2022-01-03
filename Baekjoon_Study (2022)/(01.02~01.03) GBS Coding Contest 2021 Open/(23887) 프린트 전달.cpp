#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int N, M, K, S;
int Map[501][501] = { 0, };
int bfs_vis[501][501] = { 0, };
int Prev[250001] = { 0, };
int indegree[250001] = { 0, };
int cnt[250001] = { 0, };

void BFS(int sy, int sx) {
	queue<pii> q;
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	q.push({ sy, sx });
	bfs_vis[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 7) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == 0) continue;
			if (bfs_vis[ny][nx] == 0) {
				bfs_vis[ny][nx] = bfs_vis[y][x] + 1;
				Prev[Map[ny][nx]] = Map[y][x];
				q.push({ ny, nx });
			}
			else if (bfs_vis[ny][nx] == bfs_vis[y][x] + 1) {
				Prev[Map[ny][nx]] = min(Prev[Map[ny][nx]], Map[y][x]);
			}
		}
	}
}

void TS() {
	queue<int> q;
	FOR(i, 1, K) {
		cnt[i] = 1;
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		int next = Prev[node];
		cnt[next] += cnt[node];
		if (--indegree[next] == 0) {
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(k, 1, K) {
		int y, x;
		cin >> y >> x;
		Map[y][x] = k;
	}
	cin >> S;
	int sy = 0, sx = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == S) {
				sy = i; sx = j;
			}
		}
	}
	Prev[S] = -1;
	BFS(sy, sx);
	bool flag = true;
	FOR(i, 1, K) {
		if (Prev[i] == 0) {
			cout << -1;
			flag = false;
			break;
		}
		else {
			indegree[Prev[i]]++;
		}
	}
	if (flag) {
		TS();
		FOR(i, 1, K) {
			cout << cnt[i] << " ";
		}
	}

	return 0;
}