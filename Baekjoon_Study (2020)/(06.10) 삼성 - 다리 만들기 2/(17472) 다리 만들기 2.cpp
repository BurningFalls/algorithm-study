#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[11][11];
int connection[7][7] = { 0, };
int visited[11][11] = { 0, };
int island_cnt = 0;
bool connect[7][7] = { 0, };
vector<pair<int, int>> possible_pos_v;
bool dfs_visited[7][7] = { 0, };
int min_bridge_sum = 0;

void Find_Island() {
	int cnt = 1;
	int y, x, ny, nx;
	queue<pair<int, int>> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			if (visited[i][j]) continue;
			q.push(make_pair(i, j));
			visited[i][j] = cnt;
			while (!q.empty()) {
				y = q.front().first;
				x = q.front().second;
				island_cnt = visited[y][x];
				q.pop();
				for (int k = 0; k < 4; k++) {
					ny = y + dy[k];
					nx = x + dx[k];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
					if (map[ny][nx] == 0) continue;
					if (visited[ny][nx]) continue;
					visited[ny][nx] = visited[y][x];
					q.push(make_pair(ny, nx));
				}
			}
			cnt++;
		}
	}
}

void Find_Connection() {
	int cnt;
	int island;

	for (int i = 0; i < N; i++) {
		cnt = 0;
		island = 0;
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0)
				cnt++;
			else {
				if (island != 0 && island != visited[i][j]) {
					if (cnt >= 2) {
						if (connection[island][visited[i][j]] != 0)
							connection[island][visited[i][j]] = min(cnt, connection[island][visited[i][j]]);
						else
							connection[island][visited[i][j]] = cnt;
					}
				}
				island = visited[i][j];
				cnt = 0;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cnt = 0;
		island = 0;
		for (int j = 0; j < N; j++) {
			if (visited[j][i] == 0)
				cnt++;
			else {
				if (island != 0 && island != visited[j][i]) {
					if (cnt >= 2) {
						if (connection[island][visited[j][i]] != 0)
							connection[island][visited[j][i]] = min(cnt, connection[island][visited[j][i]]);
						else
							connection[island][visited[j][i]] = cnt;
					}
				}
				island = visited[j][i];
				cnt = 0;
			}
		}
	}

	for (int i = 1; i <= island_cnt; i++) {
		for (int j = 1; j <= island_cnt; j++) {
			if (connection[i][j] == 0) continue;
			connection[j][i] = connection[i][j];
		}
	}
}

bool Is_Possible() {
	int visit[7] = { 0, };
	queue<int> q;
	int node;

	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 1; i <= island_cnt; i++) {
			if (connect[node][i] == 0) continue;
			if (visit[i]) continue;
			visit[i] = 1;
			q.push(i);
		}
	}
	for (int i = 1; i <= island_cnt; i++) {
		if (!visit[i])
			return false;
	}

	return true;
}

int Calculate() {
	int sum = 0;
	for (int i = 1; i <= island_cnt; i++) {
		for (int j = 1; j <= island_cnt; j++) {
			if (i >= j) continue;
			if (connect[i][j] == 0) continue;
			sum += connection[i][j];
		}
	}
	return sum;
}

void DFS(int node, int cnt) {
	int len = possible_pos_v.size();
	int y, x;
	if (cnt == island_cnt - 1) {
		if (!Is_Possible())
			return;
		if (min_bridge_sum == 0)
			min_bridge_sum = Calculate();
		else
			min_bridge_sum = min(min_bridge_sum, Calculate());
		return;
	}

	for (int i = node; i < len; i++) {
		y = possible_pos_v[i].first;
		x = possible_pos_v[i].second;
		connect[y][x] = 1;
		connect[x][y] = 1;
		DFS(i + 1, cnt + 1);
		connect[y][x] = 0;
		connect[x][y] = 0;
	}
}

void Set_Connection() {
	int len;
	for (int i = 1; i <= island_cnt; i++) {
		for (int j = 1; j <= island_cnt; j++) {
			if (i >= j) continue;
			if (connection[i][j] == 0) continue;
			possible_pos_v.push_back(make_pair(i, j));
		}
	}
	DFS(0, 0);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	Find_Island();
	Find_Connection();
	Set_Connection();

	if (min_bridge_sum == 0)
		cout << -1;
	else
		cout << min_bridge_sum;

	return 0;
}