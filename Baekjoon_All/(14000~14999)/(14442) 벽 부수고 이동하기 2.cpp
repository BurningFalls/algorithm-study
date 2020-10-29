#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000 + 1

int N, M, K;
char Map[MAX][MAX];
int visited[MAX][MAX][12] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS() {
	queue<pair<pii, int>> q;
	q.push({ { 1, 1 }, 0 });
	visited[1][1][0] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int wall = q.front().second;
		q.pop();
		if (y == N && x == M)
			return visited[y][x][wall];
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == '0') {
				if (visited[ny][nx][wall]) continue;
				visited[ny][nx][wall] = visited[y][x][wall] + 1;
				q.push({ {ny, nx}, wall });
			}
			else if (Map[ny][nx] == '1') {
				if (wall + 1 > K) continue;
				if (visited[ny][nx][wall + 1]) continue;
				visited[ny][nx][wall + 1] = visited[y][x][wall] + 1;
				q.push({ {ny, nx}, wall + 1 });
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