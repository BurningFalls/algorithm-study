#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int R, C;
char Map[252][252];
bool visited[252][252] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans_sheep = 0;
int ans_wolf = 0;

void BFS(int sy, int sx) {
	queue<pii> q;
	int sheep_cnt = 0;
	int wolf_cnt = 0;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (Map[y][x] == 'o')
			sheep_cnt++;
		else if (Map[y][x] == 'v')
			wolf_cnt++;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
			if (Map[ny][nx] == '#') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	if (sheep_cnt > wolf_cnt)
		ans_sheep += sheep_cnt;
	else
		ans_wolf += wolf_cnt;
}

int main() {
	FASTIO;
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (Map[i][j] == '#') continue;
			if (visited[i][j]) continue;
			BFS(i, j);
		}
	}
	cout << ans_sheep << " " << ans_wolf;

	return 0;
}