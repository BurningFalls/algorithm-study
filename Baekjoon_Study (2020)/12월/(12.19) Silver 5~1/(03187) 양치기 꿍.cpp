#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int R, C;
char arr[251][251];
bool visited[251][251] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans_sheep = 0;
int ans_wolf = 0;

void BFS(int sy, int sx) {
	queue<pii> q;
	int sheep_cnt = 0;
	int wolf_cnt = 0;
	visited[sy][sx] = 1;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (arr[y][x] == 'v')
			wolf_cnt++;
		else if (arr[y][x] == 'k')
			sheep_cnt++;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
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
			cin >> arr[i][j];
			if (arr[i][j] == '#')
				visited[i][j] = 1;
		}
	}
	FOR(i, 1, C) {
		if (visited[1][i]) continue;
		BFS(1, i);
	}
	FOR(i, 1, C) {
		if (visited[R][i]) continue;
		BFS(R, i);
	}
	FOR(i, 1, R) {
		if (visited[i][1]) continue;
		BFS(i, 1);
	}
	FOR(i, 1, R) {
		if (visited[i][C]) continue;
		BFS(i, C);
	}
	FOR(i, 2, R - 1) {
		FOR(j, 2, C - 1) {
			if (visited[i][j]) continue;
			BFS(i, j);
		}
	}
	cout << ans_sheep << " " << ans_wolf;

	return 0;
}