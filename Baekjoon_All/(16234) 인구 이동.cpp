#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, L, R;
int map[52][52];
bool row_line[52][52] = { 0, };
bool col_line[52][52] = { 0, };
int visited[52][52] = { 0, };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
// 왼쪽, 오른쪽, 위, 아래
int pop_sum;
int num_sum;
vector<int> v;

bool Open() {
	int d;
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < N; j++) {
			d = abs(map[i][j] - map[i][j + 1]);
			if (d >= L && d <= R) {
				row_line[i][j] = 1;
				flag = true;
			}
			else
				row_line[i][j] = 0;
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			d = abs(map[i][j] - map[i + 1][j]);
			if (d >= L && d <= R) {
				col_line[i][j] = 1;
				flag = true;
			}
			else
				col_line[i][j] = 0;
		}
	}
	return flag;
}

void Find(int y, int x, int gn) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
		if (visited[ny][nx]) continue;
		if (i == 0 && row_line[ny][nx] == 0) continue;
		if (i == 1 && row_line[ny][nx - 1] == 0) continue;
		if (i == 2 && col_line[ny][nx] == 0) continue;
		if (i == 3 && col_line[ny - 1][nx] == 0) continue;
		visited[ny][nx] = gn;
		pop_sum += map[ny][nx];
		num_sum += 1;
		Find(ny, nx, gn);
	}
}

int main() {
	int div;
	int cnt = 0;
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	while (Open()) {
		cnt++;
		div = 1;
		v.clear();
		v.push_back(0);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				visited[i][j] = 0;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][j]) continue;
				pop_sum = map[i][j];
				num_sum = 1;
				visited[i][j] = div;
				Find(i, j, div);
				div++;
				v.push_back(int(pop_sum / num_sum));
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = v[visited[i][j]];
			}
		}
	}
	cout << cnt;

	return 0;
}