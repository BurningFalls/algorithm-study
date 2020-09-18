#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
char Map[52][52];
int visited[51][51] = { 0, };
queue<pair<int, int>> q;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int maximum = 0;

void BFS() {
	int y, x, ny, nx;
	pair<int, int> temp;
	while (!q.empty()) {
		temp = q.front();
		y = temp.first;
		x = temp.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (Map[ny][nx] == 'W') continue;
			if (visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			maximum = max(maximum, visited[ny][nx] - 1);
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 'L') {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
				BFS();
				for (int a = 0; a < N; a++) {
					for (int b = 0; b < M; b++) {
						visited[a][b] = 0;
					}
				}
				while (!q.empty()) q.pop();
			}
		}
	}
	cout << maximum;

	return 0;
}