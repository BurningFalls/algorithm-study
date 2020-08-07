#include <iostream>
using namespace std;

int map[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];

void DFS(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (map[y][x] == 0) {
		for (int k = 1; k <= 9; k++) {
			if (row[x][k]) continue;
			if (col[y][k]) continue;
			if (square[3 * (y / 3) + x / 3][k]) continue;
			map[y][x] = k;
			row[x][k] = true;
			col[y][k] = true;
			square[3 * (y / 3) + x / 3][k] = true;
			DFS(cnt + 1);
			map[y][x] = 0;
			row[x][k] = false;
			col[y][k] = false;
			square[3 * (y / 3) + x / 3][k] = false;
		}
	}
	else {
		DFS(cnt + 1);
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				row[j][map[i][j]] = true;
				col[i][map[i][j]] = true;
				square[3 * (i / 3) + j / 3][map[i][j]] = true;
			}
		}
	}

	DFS(0);

	return 0;
}