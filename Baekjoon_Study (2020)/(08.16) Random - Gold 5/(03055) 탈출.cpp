#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int R, C;
char Map[51][51];
queue<pair<int, int>> q;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[51][51] = { 0, };
int pos_y, pos_x;
int moving[51][51] = { 0, };
int ans = -1;

void Watering() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (Map[ny][nx] == 'D' || Map[ny][nx] == 'X') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

void Moving() {
	q.push(make_pair(pos_y, pos_x));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (Map[y][x] == 'D') {
			ans = moving[y][x] - 1;
			break;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (Map[ny][nx] == 'X') continue;
			if (moving[ny][nx]) continue;
			if (visited[ny][nx] != 0 && visited[ny][nx] <= moving[y][x] + 1) continue;
			moving[ny][nx] = moving[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	FASTIO;
	cin >> R >> C;
	FOR(i, 0, R - 1) {
		FOR(j, 0, C - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == '*') {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			if (Map[i][j] == 'S') {
				moving[i][j] = 1;
				pos_y = i;
				pos_x = j;
			}
		}
	}
	Watering();
	Moving();
	if (ans != -1)
		cout << ans;
	else
		cout << "KAKTUS";

	return 0;
}