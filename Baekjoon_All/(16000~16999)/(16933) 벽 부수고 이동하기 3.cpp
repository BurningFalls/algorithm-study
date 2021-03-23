#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000 + 1

struct INF {
	int y;
	int x;
	int wall;
	bool flag;
};

int N, M, K;
char Map[MAX][MAX];
int visited[MAX][MAX][11][2] = { 0, };
int dy[5] = { -1, 1, 0, 0 };
int dx[5] = { 0, 0, -1, 1 };

int BFS() {
	queue<INF> q;
	q.push({ 1, 1, 0, 0 });
	visited[1][1][0][0] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int wall = q.front().wall;
		bool flag = q.front().flag;
		q.pop();
		if (y == N && x == M)
			return visited[y][x][wall][flag];
		if (!visited[y][x][wall][!flag]) {
			visited[y][x][wall][!flag] = visited[y][x][wall][flag] + 1;
			q.push({ y, x, wall, !flag });
		}
		FOR(i, 0, 4) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == '0') {
				if (visited[ny][nx][wall][!flag]) continue;
				visited[ny][nx][wall][!flag] = visited[y][x][wall][flag] + 1;
				q.push({ ny, nx, wall, !flag });
			}
			else if (Map[ny][nx] == '1') {
				if (wall + 1 > K) continue;
				if (flag == 1) continue;
				if (visited[ny][nx][wall + 1][!flag]) continue;
				visited[ny][nx][wall + 1][!flag] = visited[y][x][wall][flag] + 1;
				q.push({ ny, nx, wall + 1, !flag });
			}
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	cout << BFS();

	return 0;
}