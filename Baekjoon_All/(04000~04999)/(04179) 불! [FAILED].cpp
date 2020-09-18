#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[1001][1001];
int fire_visited[1001][1001] = { 0, };
bool J_visited[1001][1001] = { 0, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> fire_q;

void fire_BFS() {
	int y, x, ny, nx;
	while (!fire_q.empty()) {
		y = fire_q.front().first;
		x = fire_q.front().second;
		fire_q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= R || nx >= C || ny < 0 || nx < 0) continue;
			if (fire_visited[ny][nx]) continue;
			if (map[ny][nx] == '#') continue;
			fire_visited[ny][nx] = fire_visited[y][x] + 1;
			fire_q.push(make_pair(ny, nx));
		}
	}
}

void J_DFS(int y, int x, int cnt) {
	if (y == 0 || x == 0 || y == R - 1 || x == C - 1) {
		cout << cnt;
		exit(0);
		return;
	}
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= R || nx >= C || ny < 0 || nx < 0) continue;
		if (map[ny][nx] == '#') continue;
		if (fire_visited[ny][nx] != 0 && fire_visited[ny][nx] <= cnt + 1) continue;
		if (J_visited[ny][nx]) continue;
		J_visited[ny][nx] = 1;
		J_DFS(ny, nx, cnt + 1);
		J_visited[ny][nx] = 0;
	}
}

int main() {
	int Jy = 0, Jx = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				Jy = i;
				Jx = j;
				J_visited[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'F') {
				fire_visited[i][j] = 1;
				fire_q.push(make_pair(i, j));
			}
		}
	}
	fire_BFS();
	J_DFS(Jy, Jx, 1);
	cout << "IMPOSSIBLE";

	return 0;
}