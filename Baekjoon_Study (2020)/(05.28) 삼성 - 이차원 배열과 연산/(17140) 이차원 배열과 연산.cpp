#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, K;
//vector<vector<int>> v;
int row_cnt = 3, col_cnt = 3;
int cnt[101] = { 0, };
vector<pair<int, int>> ans_v;
int arr[101][101] = { 0, };

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

void Row_Sort(int row) {
	int len;
	ans_v.clear();
	for (int i = 1; i <= 100; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < col_cnt; i++) {
		cnt[arr[row][i]] += 1;
	}
	for (int i = 0; i < col_cnt; i++) {
		arr[row][i] = 0;
	}
	for (int i = 1; i <= 100; i++) {
		if (cnt[i] == 0) continue;
		ans_v.push_back(make_pair(i, cnt[i]));
	}
	sort(ans_v.begin(), ans_v.end(), compare);
	len = ans_v.size();
	for (int i = 0; i < min(100, len * 2); i += 2) {
		arr[row][i] = ans_v[i / 2].first;
		arr[row][i + 1] = ans_v[i / 2].second;
	}
	col_cnt = max(col_cnt, len * 2);
}

void Col_Sort(int col) {
	int len;
	ans_v.clear();
	for (int i = 1; i <= 100; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < row_cnt; i++) {
		cnt[arr[i][col]] += 1;
	}
	for (int i = 0; i < row_cnt; i++) {
		arr[i][col] = 0;
	}
	for (int i = 1; i <= 100; i++) {
		if (cnt[i] == 0) continue;
		ans_v.push_back(make_pair(i, cnt[i]));
	}
	sort(ans_v.begin(), ans_v.end(), compare);
	len = ans_v.size();
	for (int i = 0; i < min(100, len * 2); i += 2) {
		arr[i][col] = ans_v[i / 2].first;
		arr[i + 1][col] = ans_v[i / 2].second;
	}
	row_cnt = max(row_cnt, len * 2);
}

int main() {
	int num;
	int timing = 0;
	bool flag = false;
	cin >> R >> C >> K;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		if (arr[R - 1][C - 1] == K) {
			flag = true;
			break;
		}
		if (timing == 100)
			break;
		if (row_cnt >= col_cnt) {
			for (int i = 0; i < row_cnt; i++) {
				Row_Sort(i);
			}
		}
		else if (row_cnt < col_cnt) {
			for (int i = 0; i < col_cnt; i++) {
				Col_Sort(i);
			}
		}
		timing += 1;
	}

	if (flag)
		cout << timing;
	else if (!flag)
		cout << -1;

	return 0;
}