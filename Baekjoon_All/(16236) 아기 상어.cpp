#include <iostream>
#include <queue>
using namespace std;

int N;
int fish[21][21];
int dist[21][21];
int shark_y, shark_x;
queue<pair<int, int>> q;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int shark_size = 2;
int fish_cnt = 0;
int timing = 0;

void Calculate_Distance() {
	int y, x, ny, nx;
	int visited[21][21] = { 0, };

	visited[shark_y][shark_x] = 1;
	q.push(make_pair(shark_y, shark_x));

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx]) continue;
			if (shark_size < fish[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (fish[i][j] == 0 || fish[i][j] == shark_size || visited[i][j] == 0)
				dist[i][j] = 0;
			else
				dist[i][j] = visited[i][j] - 1;
		}
	}
}

bool Eat_Fish() {
	int minimum = 500;
	int m_y = -1, m_x = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == 0) continue;
			if (minimum > dist[i][j]) {
				minimum = dist[i][j];
				m_y = i;
				m_x = j;
			}
		}
	}
	if (m_y == -1 && m_x == -1)
		return false;
	shark_y = m_y;
	shark_x = m_x;
	fish_cnt += 1;
	timing += dist[m_y][m_x];
	fish[m_y][m_x] = 0;
	if (fish_cnt == shark_size) {
		shark_size += 1;
		fish_cnt = 0;
	}
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> fish[i][j];
			if (fish[i][j] == 9) {
				shark_y = i;
				shark_x = j;
				fish[i][j] = 0;
			}
		}
	}

	while (true) {
		Calculate_Distance();
		if (!Eat_Fish())
			break;
	}
	cout << timing;

	return 0;
}