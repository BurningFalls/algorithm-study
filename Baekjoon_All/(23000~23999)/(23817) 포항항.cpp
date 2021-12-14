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

int N, M;
char Map[1001][1001];
int Idx[1001][1001] = { 0, };
int visited[1001][1001];
int dist[21][21] = { 0, };
int ch[6];
bool ch_vis[21] = { 0, };
int mini = INF;

void BFS(int sy, int sx) {
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	int sidx = Idx[sy][sx];
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (Idx[y][x] != 0) {
			dist[sidx][Idx[y][x]] = visited[y][x] - 1;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == 'X') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

void DFS(int cnt, int total_dist, int idx) {
	if (cnt == 6) {
		mini = min(mini, total_dist);
		return;
	}
	FOR(i, 2, idx) {
		if (ch_vis[i]) continue;
		if (dist[ch[cnt - 1]][i] == 0) continue;
		ch_vis[i] = 1;
		ch[cnt] = i;
		DFS(cnt + 1, total_dist + dist[ch[cnt - 1]][ch[cnt]], idx);
		ch_vis[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	int idx = 1;
	int k_cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
			if (Map[i][j] == 'S') {
				Idx[i][j] = 1;
			}
			else if (Map[i][j] == 'K') {
				idx++;
				Idx[i][j] = idx;
				k_cnt++;
			}
		}
	}

	if (k_cnt < 5) {
		cout << -1;
		return 0;
	}

	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == 'X' || Map[i][j] == '.') continue;
			BFS(i, j);
		}
	}

	ch[0] = 1;
	DFS(1, 0, idx);

	cout << (mini == INF ? -1 : mini);


	return 0;
}