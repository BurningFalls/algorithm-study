#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[11][11];
int visited[11][11] = { 0, };
int paper_cnt[6] = { 0, 5, 5, 5, 5, 5 };
int min_cnt = 26;
vector<pair<int, int>> pos_v;
int one_cnt = 0;
int using_cnt = 0;

bool Check(int y, int x, int k) {
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			if (map[i][j] == 0)
				return false;
			if (visited[i][j] != 0)
				return false;
		}
	}
	return true;
}

void DFS(int i) {
	if (one_cnt == 0) {
		min_cnt = min(min_cnt, using_cnt);
		return;
	}

	int y, x;
	y = pos_v[i].first;
	x = pos_v[i].second;
	if (visited[y][x]) {
		DFS(i + 1);
		return;
	}
	for (int k = 5; k >= 1; k--) {
		if (y + k > 10 || x + k > 10) continue;
		if (using_cnt >= min_cnt)
			continue;
		if (!Check(y, x, k))
			continue;
		if (paper_cnt[k] == 0) continue;
		for (int a = y; a < y + k; a++) {
			for (int b = x; b < x + k; b++) {
				visited[a][b] = k;
				one_cnt--;
			}
		}

		paper_cnt[k]--;
		using_cnt++;

		DFS(i + 1);
		for (int a = y; a < y + k; a++) {
			for (int b = x; b < x + k; b++) {
				visited[a][b] = 0;
				one_cnt++;
			}
		}

		paper_cnt[k]++;
		using_cnt--;
	}
}

int main() {
	int paper_sum = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				pos_v.push_back(make_pair(i, j));
				one_cnt++;
			}
		}
	}

	DFS(0);

	if (min_cnt == 26)
		cout << -1;
	else
		cout << min_cnt;

	return 0;
}