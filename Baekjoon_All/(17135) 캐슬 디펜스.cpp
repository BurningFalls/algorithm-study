#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D;
bool ori_map[16][16];
bool map[16][16];
bool archer[16] = { 0, };
int dy[3] = { 0, -1, 0 };
int dx[3] = { -1, 0, 1 };
vector<pair<int, int>> enemy_pos_v;
int removed_enemy_cnt = 0;
int removed_enemy_max = 0;
int ori_enemy_cnt = 0;
int enemy_cnt = 0;

void Copy_Map() {
	enemy_cnt = ori_enemy_cnt;
	removed_enemy_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = ori_map[i][j];
		}
	}
}

void Detect_Enemy() {
	int y, x, ny, nx;
	enemy_pos_v.clear();
	for (int i = 0; i < M; i++) {
		if (!archer[i]) continue;

		queue<pair<int, int>> q;
		int visited[16][16] = { 0, };

		q.push(make_pair(N - 1, i));
		visited[N - 1][i] = 1;
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			if (visited[y][x] > D)
				break;
			if (map[y][x] == 1) {
				enemy_pos_v.push_back(make_pair(y, x));
				break;
			}
			q.pop();
			for (int j = 0; j < 3; j++) {
				ny = y + dy[j];
				nx = x + dx[j];
				if (ny < 0 || nx < 0 || nx >= M) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

void Attack_Enemy() {
	int len;
	int y, x;
	len = enemy_pos_v.size();
	for (int i = 0; i < len; i++) {
		y = enemy_pos_v[i].first;
		x = enemy_pos_v[i].second;
		if (map[y][x] == 0) continue;
		map[y][x] = 0;
		removed_enemy_cnt++;
		enemy_cnt--;
	}
}

void Move_Enemy() {
	for (int i = 0; i < M; i++) {
		if (map[N - 1][i] == 1) {
			map[N - 1][i] = 0;
			enemy_cnt--;
		}
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				map[i + 1][j] = 1;
				map[i][j] = 0;
			}
		}
	}
}

void Set_Archer(int node, int cnt) {
	if (cnt == 3) {
		Copy_Map();
		while (enemy_cnt) {
			Detect_Enemy();
			Attack_Enemy();
			Move_Enemy();
		}
		removed_enemy_max = max(removed_enemy_max, removed_enemy_cnt);
		return;
	}

	for (int i = node; i < M; i++) {
		archer[i] = 1;
		Set_Archer(i + 1, cnt + 1);
		archer[i] = 0;
	}
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ori_map[i][j];
			if (ori_map[i][j] == 1)
				ori_enemy_cnt++;
		}
	}

	Set_Archer(0, 0);

	cout << removed_enemy_max;

	return 0;
}