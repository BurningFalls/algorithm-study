#include <iostream>
#include <vector>
using namespace std;

int R, C, T;
int map[51][51];
vector<int> ac_v;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void Diffusion() {
	int temp_map[51][51] = { 0, };
	int y, x, ny, nx;
	int dif_cnt;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0 || map[i][j] == -1) continue;
			y = i;
			x = j;
			dif_cnt = map[y][x] / 5;
			for (int k = 0; k < 4; k++) {
				ny = y + dy[k];
				nx = x + dx[k];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if (map[ny][nx] == -1) continue;
				temp_map[ny][nx] += dif_cnt;
				map[y][x] -= dif_cnt;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += temp_map[i][j];
		}
	}
}

void Rotate() {
	int ac_y;

	ac_y = ac_v[0];
	for (int i = ac_y - 1; i >= 1; i--) {
		map[i][0] = map[i - 1][0];
	}
	for (int i = 0; i <= C - 2; i++) {
		map[0][i] = map[0][i + 1];
	}
	for (int i = 0; i <= ac_y - 1; i++) {
		map[i][C - 1] = map[i + 1][C - 1];
	}
	for (int i = C - 1; i >= 2; i--) {
		map[ac_y][i] = map[ac_y][i - 1];
	}
	map[ac_y][1] = 0;

	ac_y = ac_v[1];
	for (int i = ac_y + 1; i <= R - 2; i++) {
		map[i][0] = map[i + 1][0];
	}
	for (int i = 0; i <= C - 2; i++) {
		map[R - 1][i] = map[R - 1][i + 1];
	}
	for (int i = R - 1; i >= ac_y + 1; i--) {
		map[i][C - 1] = map[i - 1][C - 1];
	}
	for (int i = C - 1; i >= 2; i--) {
		map[ac_y][i] = map[ac_y][i - 1];
	}
	map[ac_y][1] = 0;
}

int main() {
	int timing = 0;
	int sum = 0;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (j == 0 && map[i][j] == -1)
				ac_v.push_back(i);
		}
	}

	while (timing < T) {
		Diffusion();
		Rotate();
		timing++;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1 || map[i][j] == 0) continue;
			sum += map[i][j];
		}
	}
	cout << sum;

	return 0;
}