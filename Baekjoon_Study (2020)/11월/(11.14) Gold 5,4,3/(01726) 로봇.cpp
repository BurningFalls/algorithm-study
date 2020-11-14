#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int M, N;
bool Map[101][101];
pair<pii, int> robot, goal;
int visited[101][101][4] = { 0, };
queue<pair<pii, int>> q;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int getC(int x) {
	if (x == 1)
		return 0;
	else if (x == 2)
		return 2;
	else if (x == 3)
		return 1;
	else if (x == 4)
		return 3;
}

bool Check(int y, int x, int dir, int cnt) {
	int ny, nx;
	ny = y, nx = x;
	FOR(i, 1, cnt) {
		ny += dy[dir];
		nx += dx[dir];
		if (Map[ny][nx] == 1)
			return false;
	}
	return true;
}

int BFS() {
	q.push(robot);
	visited[robot.first.first][robot.first.second][robot.second] = 1;
	while (!q.empty()) {
		pair<pii, int> t = q.front();
		if (t == goal)
			return visited[t.first.first][t.first.second][t.second] - 1;
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		if (y == 4 && x == 1 && dir == 1) {
			int a = 1;
		}
		FOR(i, 1, 3) {
			int ny = y + dy[dir] * i;
			int nx = x + dx[dir] * i;
			if (ny < 1 || nx < 1 || ny > M || nx > N) continue;
			if (visited[ny][nx][dir]) continue;
			if (!Check(y, x, dir, i)) continue;
			visited[ny][nx][dir] = visited[y][x][dir] + 1;
			q.push({ { ny, nx }, dir });
		}
		if (!visited[y][x][(dir + 1) % 4]) {
			visited[y][x][(dir + 1) % 4] = visited[y][x][dir] + 1;
			q.push({ {y, x}, (dir + 1) % 4 });
		}
		if (!visited[y][x][(dir + 3) % 4]) {
			visited[y][x][(dir + 3) % 4] = visited[y][x][dir] + 1;
			q.push({ {y, x}, (dir + 3) % 4 });
		}
	}
}

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(i, 1, M) FOR(j, 1, N)
		cin >> Map[i][j];
	int a, b, c;
	cin >> a >> b >> c;
	robot = { {a, b}, getC(c) };
	cin >> a >> b >> c;
	goal = { {a, b}, getC(c) };
	cout << BFS();

	return 0;
}