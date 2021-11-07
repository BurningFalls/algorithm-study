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
int Map[101][101];
int visited[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int max_len = 0;
int sum = 0;

void BFS(int sy, int sx) {
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	int vis_max = 0;
	int num = 0;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (vis_max < visited[y][x]) {
			vis_max = visited[y][x];
			num = Map[y][x];
		}
		else if (vis_max == visited[y][x]) {
			num = max(num, Map[y][x]);
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny >N || nx > M) continue;
			if (Map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (max_len < vis_max) {
		max_len = vis_max;
		sum = num + Map[sy][sx];
	}
	else if (max_len == vis_max) {
		sum = max(sum, num + Map[sy][sx]);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == 0) continue;
			BFS(i, j);
		}
	}
	cout << sum;

	return 0;
}