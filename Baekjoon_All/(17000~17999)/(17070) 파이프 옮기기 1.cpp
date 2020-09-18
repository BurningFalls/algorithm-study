#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N;
int map[18][18];
int dy[3] = { 0, 1, 1 };
int dx[3] = { 1, 1, 0 };
queue<tuple<int, int, int>> q;
// y¡¬«•, x¡¬«•, πÊ«‚(0, 1, 2)
int ans = 0;

void Move() {
	int y, x, d, ny, nx, nd;
	while (!q.empty()) {
		y = get<0>(q.front());
		x = get<1>(q.front());
		d = get<2>(q.front());
		q.pop();
		if (y == N && x == N)
			ans++;
		for (int i = 0; i < 3; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (map[ny][nx] == 1) continue;
			if (i == 0) {
				if (d == 2) continue;
			}
			else if (i == 1) {
				if (map[ny][nx - 1] == 1) continue;
				if (map[ny - 1][nx] == 1) continue;
			}
			else if (i == 2) {
				if (d == 0) continue;
			}
			q.push(make_tuple(ny, nx, i));
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	q.push(make_tuple(1, 2, 0));
	Move();

	cout << ans;

	return 0;
}