#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[51][51];
bool visited_virus[11] = { 0, };
int visited_map[51][51] = { 0, };
vector<pair<int, int>> virus_pos_v;
queue<pair<int, int>> virus_q;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited_max = 0;
int time_min = -1;

bool Spread_Virus() {
	visited_max = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1)
				visited_map[i][j] = 1;
			else
				visited_map[i][j] = 0;
		}
	}

	for (int i = 0; i < virus_pos_v.size(); i++) {
		if (!visited_virus[i]) continue;
		visited_map[virus_pos_v[i].first][virus_pos_v[i].second] = 1;
		virus_q.push(make_pair(virus_pos_v[i].first, virus_pos_v[i].second));
	}

	int y, x, ny, nx;
	while (!virus_q.empty()) {
		y = virus_q.front().first;
		x = virus_q.front().second;
		virus_q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (map[ny][nx] == 1) continue;
			if (visited_map[ny][nx]) continue;
			visited_map[ny][nx] = visited_map[y][x] + 1;
			if (map[ny][nx] != 2)
				visited_max = max(visited_max, visited_map[ny][nx]);
			virus_q.push(make_pair(ny, nx));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited_map[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void Select_Virus(int node, int cnt) {
	if (cnt == M) {
		if (Spread_Virus()) {
			if (time_min == -1)
				time_min = visited_max - 1;
			else
				time_min = min(time_min, visited_max - 1);
		}

		return;
	}

	for (int i = node; i < virus_pos_v.size(); i++) {
		if (visited_virus[i]) continue;
		visited_virus[i] = 1;
		Select_Virus(i + 1, cnt + 1);
		visited_virus[i] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus_pos_v.push_back(make_pair(i, j));
		}
	}

	Select_Virus(0, 0);

	cout << time_min;

	return 0;
}