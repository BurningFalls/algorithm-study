#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define INF 100

int N, M;
int map[9][9];
vector<tuple<int, int, int>> cctv_v;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int Blind_Spot_min = INF;
// 0:오른쪽, 1:아래, 2:왼쪽, 3:위

void Watch(int dir, int y, int x) {
	int ny = y, nx = x;
	while (true) {
		ny += dy[dir];
		nx += dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			break;
		if (map[ny][nx] == 6)
			break;
		if (map[ny][nx] >= 1 && map[ny][nx] <= 5) continue;
		if (map[ny][nx] == 8) continue;
		map[ny][nx] = 8;
	}
}

void DFS(int cnt) {
	int cctv, y, x;
	int temp_map[9][9];
	int Blind_Spot_cnt = 0;
	if (cnt == cctv_v.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					Blind_Spot_cnt++;
			}
		}
		Blind_Spot_min = min(Blind_Spot_min, Blind_Spot_cnt);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
	cctv = get<0>(cctv_v[cnt]);
	y = get<1>(cctv_v[cnt]);
	x = get<2>(cctv_v[cnt]);
	if (cctv == 1) {
		for (int i = 0; i < 4; i++) {
			Watch(i, y, x);
			DFS(cnt + 1);
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < M; b++) {
					map[a][b] = temp_map[a][b];
				}
			}
		}
	}
	else if (cctv == 2) {
		for (int i = 0; i < 2; i++) {
			Watch(i, y, x);
			Watch(i + 2, y, x);
			DFS(cnt + 1);
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < M; b++) {
					map[a][b] = temp_map[a][b];
				}
			}
		}
	}
	else if (cctv == 3) {
		for (int i = 0; i < 4; i++) {
			Watch(i, y, x);
			Watch((i + 1) % 4, y, x);
			DFS(cnt + 1);
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < M; b++) {
					map[a][b] = temp_map[a][b];
				}
			}
		}
	}
	else if (cctv == 4) {
		for (int i = 0; i < 4; i++) {
			Watch(i, y, x);
			Watch((i + 1) % 4, y, x);
			Watch((i + 2) % 4, y, x);
			DFS(cnt + 1);
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < M; b++) {
					map[a][b] = temp_map[a][b];
				}
			}
		}
	}
	else if (cctv == 5) {
		Watch(0, y, x);
		Watch(1, y, x);
		Watch(2, y, x);
		Watch(3, y, x);
		DFS(cnt + 1);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				map[a][b] = temp_map[a][b];
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)
				cctv_v.push_back(make_tuple(map[i][j], i, j));
		}
	}

	DFS(0);

	cout << Blind_Spot_min;

	return 0;
}