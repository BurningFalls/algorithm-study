#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int r, c;
vector<vector<int>> Map(5, vector<int>(5));
vector<vector<int>> visited(5, vector<int>(5, 0));
vector<vector<vector<int>>> goal(5, vector<vector<int>>(5, vector<int>(4, -1)));
vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };

int BFS() {
	queue<pii> q;
	q.push({ r, c });
	visited[r][c] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (Map[y][x] == 1) {
			return visited[y][x] - 1;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > 4 || nx > 4) continue;
			if (Map[ny][nx] == -1) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
		FOR(i, 0, 3) {
			int ny = (dy[i] == 0 ? y : goal[y][x][i]);
			int nx = (dx[i] == 0 ? x : goal[y][x][i]);
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return -1;
}

int main() {
	FASTIO;
	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			cin >> Map[i][j];
		}
	}
	cin >> r >> c;

	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			if (Map[i][j] == 1 || Map[i][j] == -1) continue;
			FOR(k, 0, 3) {
				int y = i, x = j;
				do {
					y += dy[k];
					x += dx[k];
				} while (y >= 0 && x >= 0 && y <= 4 && x <= 4 && Map[y][x] != -1 && Map[y][x] != 7);
				
				if (y < 0 || x < 0 || y > 4 || x > 4 || Map[y][x] == -1) {
					y -= dy[k];
					x -= dx[k];
				}
				goal[i][j][k] = abs(dy[k]) * y + abs(dx[k]) * x;
			}
		}
	}

	cout << BFS();

	return 0;
}