#include <iostream>
#include <queue>
using namespace std;

bool check[101][101];

int weak_color(int n, char** map, bool is_weak) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
	int result = 0;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(0, 0));
	int col = 0, row = 0;
	pair<int, int> temp;
	check[0][0] = true;
	int for_count = 0;

	if (is_weak == true) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 'G') {
					map[i][j] = 'R';
				}
			}
		}
	}

	while (for_count < n * n) {
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			col = temp.first;
			row = temp.second;
			if (row + 1 < n) {
				if (check[col][row + 1] == false && map[col][row] == map[col][row + 1]) {
					q.push(pair<int, int>(col, row + 1));
					check[col][row + 1] = true;
				}
			}
			if (col + 1 < n) {
				if (check[col + 1][row] == false && map[col][row] == map[col + 1][row]) {
					q.push(pair<int, int>(col + 1, row));
					check[col + 1][row] = true;
				}
			}
			if (row - 1 >= 0) {
				if (check[col][row - 1] == false && map[col][row] == map[col][row - 1]) {
					q.push(pair<int, int>(col, row - 1));
					check[col][row - 1] = true;
				}
			}
			if (col - 1 >= 0) {
				if (check[col - 1][row] == false && map[col][row] == map[col - 1][row]) {
					q.push(pair<int, int>(col - 1, row));
					check[col - 1][row] = true;
				}
			}
		}
		result++;
		for_count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == false) {
					q.push(pair<int, int>(i, j));
					check[i][j] = true;
					break;
				}
				else
					for_count++;
			}
			if (!q.empty())
				break;
		}
	}
	return result;
}


int main() {
	int N;
	cin >> N;
	char** map = new char* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new char[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	cout << weak_color(N, map, false) << " ";
	cout << weak_color(N, map, true) << endl;


	return 0;
}