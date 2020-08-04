#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int M, N, H;
int tomato[101][101][101];
int visited[101][101][101] = { 0, };
int dh[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 0, 0, 1, -1 };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
queue<tuple<int, int, int>> q;
int tomato_cnt = 0;
int visited_max = 1;

void BFS() {
	int h, y, x, nh, ny, nx;
	while (!q.empty()) {
		h = get<0>(q.front());
		y = get<1>(q.front());
		x = get<2>(q.front());
		q.pop();
		tomato_cnt--;
		for (int i = 0; i < 6; i++) {
			nh = h + dh[i];
			ny = y + dy[i];
			nx = x + dx[i];
			if (nh < 0 || ny < 0 || nx < 0 || nh >= H || ny >= N || nx >= M) continue;
			if (visited[nh][ny][nx]) continue;
			visited[nh][ny][nx] = visited[h][y][x] + 1;
			visited_max = max(visited_max, visited[nh][ny][nx]);
			q.push(make_tuple(nh, ny, nx));
		}
	}
}

int main() {
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tomato[h][i][j];
				if (tomato[h][i][j] == 1) {
					q.push(make_tuple(h, i, j));
					visited[h][i][j] = 1;
					tomato_cnt++;
				}
				else if (tomato[h][i][j] == 0) {
					tomato_cnt++;
				}
				else if (tomato[h][i][j] == -1) {
					visited[h][i][j] = 1;
				}
			}
		}
	}

	BFS();

	if (tomato_cnt != 0)
		cout << -1;
	else
		cout << visited_max - 1;

	return 0;
}