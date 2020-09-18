#include <iostream>
using namespace std;

int M, N;
int map[501][501];
int Cnt[501][501];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int cnt = 0;
int DFS(int y, int x) {
	if (Cnt[y][x] != -1)
		return Cnt[y][x];
	if (y < 0 || x < 0 || y >= M || x >= N)
		return 0;
	if (y == 0 && x == 0)
		return 1;
	int ny, nx;
	Cnt[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (map[ny][nx] <= map[y][x]) continue;
		Cnt[y][x] += DFS(ny, nx);
	}
	return Cnt[y][x];
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			Cnt[i][j] = -1;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << DFS(M - 1, N - 1);

	return 0;
}