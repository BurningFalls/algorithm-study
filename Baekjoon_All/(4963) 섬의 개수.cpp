#include <iostream>
#include <queue>
using namespace std;

int W, H;
int map[51][51];
int visited[51][51] = { 0, };
queue<pair<int, int>> q;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int island_cnt = 0;

void BFS() {
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	while (true) {
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 0) continue;
				if (visited[i][j]) continue;
				island_cnt++;
				q.push(make_pair(i, j));
				BFS();
			}
		}
		cout << island_cnt << "\n";
		island_cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				visited[i][j] = 0;
			}
		}
	}

	return 0;
}