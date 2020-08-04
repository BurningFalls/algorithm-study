#include <iostream>
using namespace std;

int R, C;
char map[10002][502];
bool visited[10002][502] = { 0, };
int dy[3] = { -1, 0, 1 };
int dx[3] = { 1, 1, 1 };
bool flag;
int ans = 0;

void DFS(int y, int x) {
	if (x == C) {
		flag = true;
		ans++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || ny > R) continue;
		if (map[ny][nx] == 'x') continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		DFS(ny, nx);
		if (flag == true)
			break;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];
	for (int i = 1; i <= R; i++) {
		flag = false;
		visited[i][1] = 1;
		DFS(i, 1);
	}
	cout << ans;

	return 0;
}