#include <iostream>
#include <vector>
using namespace std;

int map[51][51] = { 0, };
int visited[51][51] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int col, int row) {
	int new_col, new_row;
	visited[col][row] = 1;
	for (int i = 0; i < 4; i++) {
		new_col = col + dy[i];
		new_row = row + dx[i];
		if (map[new_col][new_row] == 1 && !visited[new_col][new_row]) {
			visited[new_col][new_row] = 1;
			dfs(new_col, new_row);
		}
	}
}

int main() {
	int T;
	int M, N, K;
	int X, Y;
	int group;
	cin >> T;
	for (int a = 0; a < T; a++) {
		group = 0;
		cin >> M >> N >> K;
		for (int i = 1; i <= K; i++) {
			cin >> X >> Y;
			map[Y + 1][X + 1] = 1;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					group++;
					dfs(i, j);
				}
			}
		}
		cout << group << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
	}


	return 0;
}