#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char arr[101][101];
int visited[101][101] = { 0, };
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N, M;

void BFS() {
	int x, y;
	int ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (visited[ny][nx]) continue;
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (arr[ny][nx] == '0') continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	BFS();

	cout << visited[N - 1][M - 1];

	return 0;
}
