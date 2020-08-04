#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int visited[101][101] = { 0, };
int M, N;
int blank_count;

void DFS(int y, int x) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
		if (map[ny][nx] == 1) continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		blank_count++;
		DFS(ny, nx);
	}
}

int main() {
	int K;
	int group_count = 0;
	vector<int> blank;
	cin >> M >> N >> K;
	int** arr = new int* [K];
	for (int i = 0; i < K; i++) {
		arr[i] = new int[4];
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		for (int j = arr[i][1]; j < arr[i][3]; j++) {
			for (int k = arr[i][0]; k < arr[i][2]; k++) {
				if (map[j][k] == 1) continue;
				map[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			if (map[i][j] == 0) {
				blank_count = 1;
				group_count++;
				visited[i][j] = 1;
				DFS(i, j);
				blank.push_back(blank_count);
			}
		}
	}
	cout << group_count << endl;
	sort(blank.begin(), blank.end());
	for (int i = 0; i < blank.size(); i++) {
		cout << blank[i] << " ";
	}

	return 0;
}