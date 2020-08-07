#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
bool map[11][11];
bool Check[11][11] = { 0, };
int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { -1, 1, -1, 1 };
int bs_cnt = 0;
int max_bs_cnt = 0;
vector<pair<int, int>> v;

void Checking(int y, int x) {
	int ny, nx;
	Check[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ny = y, nx = x;
			while (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				ny += dy[i];
				nx += dx[i];
				Check[ny][nx] = 1;
			}
		}
	}
}

void DFS(int cnt) {
	if (cnt == v.size()) {
		max_bs_cnt = max(max_bs_cnt, bs_cnt);
		return;
	}

	bool temp_Check[11][11];
	int cur_y, cur_x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp_Check[i][j] = Check[i][j];
		}
	}
	for (int i = cnt; i < v.size(); i++) {
		cur_y = v[i].first;
		cur_x = v[i].second;
		if (Check[cur_y][cur_x]) {
			cnt++;
			continue;
		}
		bs_cnt++;
		Checking(cur_y, cur_x);
		DFS(cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Check[i][j] = temp_Check[i][j];
			}
		}
		bs_cnt--;
	}
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	DFS(0);
	cout << max_bs_cnt;

	return 0;
}