#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int H, W;
char Map[21][21];
int visited[21][21][1025];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int dust_cnt;

int BFS(int sy, int sx) {
	queue<pair<pii, int>> q;
	visited[sy][sx][0] = 1;
	q.push({ {sy, sx}, 0 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int state = q.front().second;
		int cnt = 0;
		FOR(i, 0, 9) {
			if (state & (1 << i))
				cnt++;
		}
		q.pop();
		if (cnt == dust_cnt)
			return visited[y][x][state] - 1;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > H || nx < 1 || nx > W) continue;
			if (Map[ny][nx] == 'x') continue;
			if (Map[ny][nx] >= 'A' && Map[ny][nx] <= 'J') {
				int new_state = state | (1 << (Map[ny][nx] - 'A'));
				if (visited[ny][nx][new_state]) continue;
				visited[ny][nx][new_state] = visited[y][x][state] + 1;
				q.push({ { ny, nx }, new_state });
			}
			else {
				if (visited[ny][nx][state]) continue;
				visited[ny][nx][state] = visited[y][x][state] + 1;
				q.push({ { ny, nx }, state });
			}
		}
	}
	return -1;
}

int main() {
	FASTIO;
	int sy = -1, sx = -1;
	while (true) {
		memset(visited, 0, sizeof(visited));
		dust_cnt = 0;
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				cin >> Map[i][j];
				if (Map[i][j] == 'o') {
					sy = i;
					sx = j;
				}
				else if (Map[i][j] == '*') {
					Map[i][j] = dust_cnt + 'A';
					dust_cnt++;
				}
			}
		}
		cout << BFS(sy, sx) << "\n";
	}

	return 0;
}