#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int arr[101][101];
int arr_min = 200, arr_max = 0;

bool BFS(int limit) {
	int minimum, maximum;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int y, x, ny, nx;
	for (int i = 0; i <= limit; i++) {
		minimum = arr[0][0] - limit + i;
		maximum = arr[0][0] + i;
		if (minimum < arr_min) continue;
		if (maximum > arr_max) continue;
		queue<pair<int, int>> q;
		bool visited[101][101] = { 0, };
		q.push(make_pair(0, 0));
		visited[0][0] = 1;
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			if (y == N - 1 && x == N - 1) {
				return true;
			}
			for (int j = 0; j < 4; j++) {
				ny = y + dy[j];
				nx = x + dx[j];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (visited[ny][nx]) continue;
				if (arr[ny][nx] < minimum) continue;
				if (arr[ny][nx] > maximum) continue;
				visited[ny][nx] = 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	return false;
}

int main() {
	int left, right, mid;
	int ans = 200;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			arr_min = min(arr_min, arr[i][j]);
			arr_max = max(arr_max, arr[i][j]);
		}
	}
	left = 0;
	right = arr_max - arr_min;
	while (right - left >= 0) {
		mid = (left + right) / 2;
		if (BFS(mid)) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;
}