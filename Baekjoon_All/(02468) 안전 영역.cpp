#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int maximum = 0;
int map[101][101];
bool visited[101][101] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> safe;

void DFS(int y, int x, int mh) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= N || ny < 0 || nx < 0 || nx >= N) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] > mh) {
			visited[ny][nx] = 1;
			DFS(ny, nx, mh);
		}
	}
}

int main() {
	int cnt;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maximum < map[i][j]) {
				maximum = map[i][j];
			}
		}
	}

	safe.push_back(1);
	for (int h = 1; h < maximum; h++) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				if (map[i][j] > h) {
					visited[i][j] = 1;
					cnt++;
					DFS(i, j, h);
				}
			}
		}
		safe.push_back(cnt);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}
	}
	safe.push_back(0);

	cout << *max_element(safe.begin(), safe.end());

	return 0;
}