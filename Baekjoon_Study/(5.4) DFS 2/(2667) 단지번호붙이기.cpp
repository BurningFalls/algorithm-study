#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char map[27][27];
vector<int> v;
int visited[26][26] = { 0, };
int counting;
vector<int> counting_v;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int col, int row) {
	int new_col, new_row;
	counting++;
	visited[col][row] = 1;
	for (int i = 0; i < 4; i++) {
		new_col = col + dy[i];
		new_row = row + dx[i];
		if (map[new_col][new_row] == '1' && !visited[new_col][new_row]) {
			dfs(new_col, new_row);
		}
	}
}

int main() {
	int len;
	cin >> N;
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			map[i][j] = '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == '1' && visited[i][j] == 0) {
				counting = 0;
				dfs(i, j);
				counting_v.push_back(counting);
			}
		}
	}
	len = counting_v.size();
	cout << len << endl;
	sort(counting_v.begin(), counting_v.end());
	for (int i = 0; i < len; i++) {
		cout << counting_v[i] << endl;
	}

	return 0;
}