#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
bool map[101][101];
bool enc_spc[101][101] = { 0, };
int no_chz_vis[101][101] = { 0, };
bool wall_flag;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> no_chz;

void BFS(int cnt) {
	int y, x, ny, nx;
	while (!no_chz.empty()) {
		y = no_chz.front().first;
		x = no_chz.front().second;
		no_chz.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N - 2 || nx > M - 2) continue;
			if (map[ny][nx] == 1) continue;
			if (no_chz_vis[ny][nx]) continue;
			if (ny == 1 || nx == 1 || ny == N - 2 || nx == M - 2)
				wall_flag = true;
			no_chz_vis[ny][nx] = cnt;
			no_chz.push(make_pair(ny, nx));
		}
	}
}

bool end_Check() {
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 2; j++) {
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}

int main() {
	int no_chz_cnt;
	int arrow_cnt;
	int Time = 0;
	vector<pair<int, int>> dis_spc;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (!end_Check()) {
		dis_spc.clear();
		no_chz_cnt = 1;
		for (int i = 1; i <= N - 2; i++) {
			for (int j = 1; j <= M - 2; j++) {
				no_chz_vis[i][j] = 0;
				enc_spc[i][j] = 0;
			}
		}
		for (int i = 1; i <= N - 2; i++) {
			for (int j = 1; j <= M - 2; j++) {
				if (map[i][j] == 0 && no_chz_vis[i][j] == 0) {
					wall_flag = false;
					no_chz_vis[i][j] = no_chz_cnt;
					if (i == 1 || j == 1 || i == N - 2 || j == M - 2)
						wall_flag = true;
					no_chz.push(make_pair(i, j));
					BFS(no_chz_cnt);
					if (wall_flag == false) {
						for (int a = 1; a <= N - 2; a++) {
							for (int b = 1; b <= M - 2; b++) {
								if (no_chz_vis[a][b] == no_chz_cnt) {
									enc_spc[a][b] = 1;
								}
							}
						}
					}
					no_chz_cnt++;
				}
			}
		}
		for (int i = 1; i <= N - 2; i++) {
			for (int j = 1; j <= M - 2; j++) {
				if (map[i][j] == 1) {
					arrow_cnt = 0;
					for (int k = 0; k < 4; k++) {
						if (map[i + dy[k]][j + dx[k]] == 0 && enc_spc[i + dy[k]][j + dx[k]] == 0) {
							arrow_cnt++;
						}
					}
					if (arrow_cnt >= 2) {
						dis_spc.push_back(make_pair(i, j));
					}
				}
			}
		}
		for (int i = 0; i < dis_spc.size(); i++) {
			map[dis_spc[i].first][dis_spc[i].second] = 0;
		}
		Time++;
	}

	cout << Time;

	return 0;
}