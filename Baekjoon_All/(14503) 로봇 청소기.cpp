#include <iostream>
using namespace std;

int N, M;
int R, C, D;
int map[51][51];
bool visited[51][51] = { 0, };
int ans = 0;

int dy[4] = { -1, 0, 1, 0 }; // 위, 오른쪽, 아래, 왼쪽
int dx[4] = { 0, 1, 0, -1 };

void Cleaning(int y, int x, int d) {
	int ny, nx;
	int cnt = 0;
	bool dir_visited[4] = { 0, };
	if (visited[y][x] == 0) {
		ans++;
		visited[y][x] = 1;
	}
	d = (d + 3) % 4;
	for (int i = d; dir_visited[i] == 0; i = (i + 3) % 4) {
		dir_visited[i] = 1;
		ny = y + dy[i];
		nx = x + dx[i];
		if (visited[ny][nx]) continue;
		if (map[ny][nx]) continue;
		Cleaning(ny, nx, i);
		break;
	}
	for (int i = 0; i < 4; i++) {
		if (dir_visited[i])
			cnt++;
	}
	if (cnt == 4) {
		d = (d + 1) % 4;
		ny = y + dy[(d + 2) % 4];
		nx = x + dx[(d + 2) % 4];
		if (map[ny][nx] == 0) {
			Cleaning(ny, nx, d);
		}
		else {
			cout << ans;
			exit(0);
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> R >> C >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	Cleaning(R, C, D);

	return 0;
}