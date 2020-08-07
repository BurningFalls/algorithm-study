#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[101][101];
int visited[101][101] = { 0, };
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sword_y, sword_x;
int sword_time = 0;
int min_swordtime = -1;

void BFS_nosword() {
	int x, y, nx, ny;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (visited[ny][nx] != 0) continue;
			if (ny >= N || ny < 0 || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 1) continue;
			if (map[ny][nx] == 2) {
				sword_time = visited[y][x];
				if (min_swordtime == -1)
					min_swordtime = sword_time;
				else
					min_swordtime = min(min_swordtime, sword_time);
				continue;
			}
			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	int T;
	int nosword = -1;
	int sword;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				sword_y = i;
				sword_x = j;
			}
		}
	}
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	BFS_nosword();

	nosword = visited[N - 1][M - 1] - 1;

	int dx = (M - 1) - sword_x;
	int dy = (N - 1) - sword_y;
	sword = min_swordtime + (dx + dy);

	if (visited[N - 1][M - 1] == 0) {
		if (min_swordtime == -1)
			cout << "Fail";
		else {
			if (sword <= T)
				cout << sword;
			else
				cout << "Fail";
		}
	}
	else {
		if (min_swordtime == -1) {
			if (nosword <= T)
				cout << nosword;
			else
				cout << "Fail";
		}
		else {
			if (min(nosword, sword) <= T)
				cout << min(nosword, sword);
			else
				cout << "Fail";
		}
	}

	return 0;
}