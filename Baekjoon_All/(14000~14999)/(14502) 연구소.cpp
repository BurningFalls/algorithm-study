#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[9][9];
int temp_map[9][9];
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
vector<pair<int, int>> empty_pos_v;
vector<pair<int, int>> virus_pos_v;
queue<pair<int, int>> virus_pos_q;
int safe_zone_max = 0;

void Copy_Map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
}

void Spread_Virus() {
	int y, x, ny, nx;

	for (int i = 0; i < virus_pos_v.size(); i++) {
		y = virus_pos_v[i].first;
		x = virus_pos_v[i].second;
		virus_pos_q.push(make_pair(y, x));
	}

	while (!virus_pos_q.empty()) {
		y = virus_pos_q.front().first;
		x = virus_pos_q.front().second;
		virus_pos_q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (temp_map[ny][nx] != 0) continue;
			temp_map[ny][nx] = 2;
			virus_pos_q.push(make_pair(ny, nx));
		}
	}
}

void Calculate_SafeZone() {
	int safe_zone_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp_map[i][j] == 0) {
				safe_zone_cnt++;
			}
		}
	}
	safe_zone_max = max(safe_zone_max, safe_zone_cnt);
}

void Make_Wall(int node, int cnt) {
	if (cnt == 3) {
		Copy_Map();
		Spread_Virus();
		Calculate_SafeZone();
		return;
	}
	for (int i = node; i < empty_pos_v.size(); i++) {
		int new_wall_y = empty_pos_v[i].first;
		int new_wall_x = empty_pos_v[i].second;
		map[new_wall_y][new_wall_x] = 1;
		Make_Wall(i + 1, cnt + 1);
		map[new_wall_y][new_wall_x] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				empty_pos_v.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				virus_pos_v.push_back(make_pair(i, j));
		}
	}

	Make_Wall(0, 0);

	cout << safe_zone_max;

	return 0;
}