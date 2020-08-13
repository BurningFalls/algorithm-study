#include <iostream>
using namespace std;

int R, C;
char map[22][22];
int visited[22][22] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int albet[26] = { 0, }; // -65
int maximum = 1;

void DFS(int y, int x, int cnt) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= R || ny < 0 || nx < 0 || nx >= C) continue;
		if (visited[ny][nx]) continue;
		if (albet[int(map[ny][nx]) - 65]) continue;
		visited[ny][nx] = 1;
		albet[int(map[ny][nx] - 65)] = 1;
		DFS(ny, nx, cnt + 1);
		albet[int(map[ny][nx] - 65)] = 0;
		visited[ny][nx] = 0;
	}
	if (maximum < cnt) {
		maximum = cnt;
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	visited[0][0] = 1;
	albet[int(map[0][0]) - 65] = 1;
	DFS(0, 0, 1);

	cout << maximum;

	return 0;
}