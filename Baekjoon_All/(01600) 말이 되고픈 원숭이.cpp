#include <iostream>
#include <queue>
using namespace std;

int K;
int W, H;
bool map[201][201];
bool visited[201][201][31] = { 0, };
int dy_mon[4] = { 0, 0, -1, 1 };
int dx_mon[4] = { -1, 1, 0, 0 };
int dy_hor[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dx_hor[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
// (ny, nx), (hor_cnt, mon_cnt)
queue<pair<pair<int, int>, pair<int, int>>> q;

int BFS() {
	int y, x, ny, nx, hor_cnt, mon_cnt;
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		hor_cnt = q.front().second.first;
		mon_cnt = q.front().second.second;
		q.pop();
		if (y == H - 1 && x == W - 1)
			return hor_cnt + mon_cnt;
		for (int i = 0; i < 4; i++) {
			ny = y + dy_mon[i];
			nx = x + dx_mon[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (map[ny][nx] == 1) continue;
			if (visited[ny][nx][hor_cnt]) continue;
			visited[ny][nx][hor_cnt] = 1;
			q.push(make_pair(make_pair(ny, nx), make_pair(hor_cnt, mon_cnt + 1)));
		}
		if (hor_cnt < K) {
			for (int i = 0; i < 8; i++) {
				ny = y + dy_hor[i];
				nx = x + dx_hor[i];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
				if (map[ny][nx] == 1) continue;
				if (visited[ny][nx][hor_cnt + 1]) continue;
				visited[ny][nx][hor_cnt + 1] = 1;
				q.push(make_pair(make_pair(ny, nx), make_pair(hor_cnt + 1, mon_cnt)));
			}
		}
	}
	return -1;
}

int main() {
	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	visited[0][0][0] = 1;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	cout << BFS();

	return 0;
}