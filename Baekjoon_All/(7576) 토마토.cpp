#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int map[1001][1001];
int visited[1001][1001] = { 0, };
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS() {
	int y, x;
	int ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= N || ny < 0 || nx < 0 || nx >= M) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	bool imp_flag = false;
	int maximum = -1;

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			if (map[i][j] == -1) {
				visited[i][j] = -1;
			}
		}
	}

	BFS();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				imp_flag = true;
				break;
			}
			else if (visited[i][j] == -1) {
				continue;
			}
			else {
				maximum = max(maximum, visited[i][j]);
			}
		}
	}

	if (imp_flag) {
		cout << -1;
	}
	else {
		cout << maximum - 1;
	}

	return 0;
}
