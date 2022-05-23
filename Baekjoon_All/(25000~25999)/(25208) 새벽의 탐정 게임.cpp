#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF int(2e9)
#define LINF ll(1e18)

struct NODE {
	int y;
	int x;
	int hole;
};

int N, M;
char Map[501][501];
int visited[501][501][6];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int dh[4][6] = { {5, 4, 2, 3, 0, 1}, {4, 5, 2, 3, 1, 0},
				{3, 2, 0, 1, 4, 5}, {2, 3, 1, 0, 4, 5} };

int BFS(int sy, int sx) {
	queue<NODE> q;
	q.push({ sy, sx, 0 });
	visited[sy][sx][0] = 1;
	if (Map[sy][sx] == 'R') {
		return 0;
	}

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int h = q.front().hole;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nh = dh[i][h];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == '#') continue;
			if (Map[ny][nx] == 'R' && nh == 0) {
				return visited[y][x][h];
			}
			else if (Map[ny][nx] == 'R' && nh != 0) {
				continue;
			}
			if (visited[ny][nx][nh]) continue;
			visited[ny][nx][nh] = visited[y][x][h] + 1;
			q.push({ ny, nx, nh });
		}
	}

	return -1;
}

int main() {
	FASTIO;
	memset(visited, 0, sizeof(visited));
	cin >> N >> M;
	int sy = 0, sx = 0;
	int ey = 0, ex = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
			if (Map[i][j] == 'D') {
				sy = i, sx = j;
			}
		}
	}

	cout << BFS(sy, sx);

	return 0;
}