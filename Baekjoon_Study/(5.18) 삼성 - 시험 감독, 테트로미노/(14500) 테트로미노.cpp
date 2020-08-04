#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int map[501][501];
int dx[19][4] = { {0, 1, 2, 3}, {0, 1, 0, 1}, {0, 0, 0, 1},
{0, 0, 1, 1}, {0, 1, 2, 1}, {0, 0, 0, 0}, {0, 1, 2, 0}, {0, 1, 1, 1},
{0, 0, 1, 2}, {0, 0, -1, 0}, {0, 1, 2, 2}, {0, 1, 0, 0}, {0, -2, -1, 0},
{0, 1, -1, 0}, {0, -1, 0, -1}, {0, 1, 1, 2}, {0, 0, 1, 0}, {0, -1, 0, 1},
{0, -1, 0, 0} };
int dy[19][4] = { {0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 2, 2},
{0, 1, 1, 2}, {0, 0, 0, 1}, {0, 1, 2, 3}, {0, 0, 0, 1}, {0, 0, 1, 2},
{0, 1, 1, 1}, {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 1, 1, 1},
{0, 0, 1, 1}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}, {0, 1, 1, 1},
{0, 1, 1, 2} };

int Check(int y, int x) {
	int ny, nx;
	int sum;
	int maximum = 0;
	for (int j = 0; j < 19; j++) {
		sum = 0;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[j][i];
			nx = x + dx[j][i];
			if (ny >= N || ny < 0 || nx < 0 || nx >= M) continue;
			sum += map[ny][nx];
		}
		maximum = max(maximum, sum);
	}
	return maximum;
}

int main() {
	int total_max = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			total_max = max(Check(i, j), total_max);
		}
	}
	cout << total_max;

	return 0;
}