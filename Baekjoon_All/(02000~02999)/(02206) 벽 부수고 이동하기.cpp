#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
char Map[1001][1001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<tuple<int, int, bool>> q;
int visited[1001][1001][2] = { 0, };

void BFS() {
	q.push(make_tuple(1, 1, 0));
	visited[1][1][0] = 1;
	while (!q.empty()) {
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		bool flag = get<2>(q.front());
		q.pop();
		if (y == N && x == M)
			break;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (!flag) {
				if (Map[ny][nx] == '0') {
					if (visited[ny][nx][0]) continue;
					visited[ny][nx][0] = visited[y][x][0] + 1;
					q.push(make_tuple(ny, nx, 0));
				}
				else if (Map[ny][nx] == '1') {
					if (visited[ny][nx][1]) continue;
					visited[ny][nx][1] = visited[y][x][0] + 1;
					q.push(make_tuple(ny, nx, 1));
				}
			}
			else if (flag) {
				if (Map[ny][nx] == '1') continue;
				if (visited[ny][nx][1]) continue;
				visited[ny][nx][1] = visited[y][x][1] + 1;
				q.push(make_tuple(ny, nx, 1));
			}
		}
	}
	if (visited[N][M][0] == 0 && visited[N][M][1] == 0)
		cout << -1;
	else if (visited[N][M][0] == 0)
		cout << visited[N][M][1];
	else if (visited[N][M][1] == 0)
		cout << visited[N][M][0];
	else
		cout << min(visited[N][M][0], visited[N][M][1]);
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	BFS();

	return 0;
}