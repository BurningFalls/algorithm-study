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
#define MAX 2001

int N, M, K;
vector<vector<int>> Map(MAX, vector<int>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<pii> q;

void BFS_man() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x] == K + 1) continue;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (Map[ny][nx] == 4) continue;
			visited[ny][nx] = visited[y][x] + 1;
			Map[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int BFS(int sy, int sx) {
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			visited[i][j] = 0;
		}
	}
	queue<pii> q;
	visited[sy][sx] = 1;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (Map[ny][nx] == 1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			if (Map[ny][nx] == 2) {
				return visited[y][x];
			}
			q.push({ ny, nx });
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	int py = 0, px = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 4) {
				py = i, px = j;
			}
		}
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			if (Map[i][j] == 3) {
				visited[i][j] = 1;
				Map[i][j] = 1;
				q.push({ i, j });
			}
		}
	}
	BFS_man();
	cout << BFS(py, px);

	return 0;
}