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

int N, M, K;
vector<vector<int>> Map;
queue<pii> q1, q2;
vector<vector<int>> visited;
vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };

void BFS1() {
	while (!q1.empty()) {
		int y = q1.front().first;
		int x = q1.front().second;
		q1.pop();
		if (visited[y][x] - 1 == K) continue;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q1.push({ ny, nx });
			if (Map[ny][nx] <= 2) {
				Map[ny][nx] = 3;
			}
		}
	}
}

int BFS2(int sy, int sx) {
	visited = vector<vector<int>>(N, vector<int>(M, 0));
	visited[sy][sx] = 1;
	q2.push({ sy, sx });
	while (!q2.empty()) {
		int y = q2.front().first;
		int x = q2.front().second;
		q2.pop();
		if (Map[y][x] == 2) {
			return visited[y][x] - 1;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (Map[ny][nx] != 0 && Map[ny][nx] != 2) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q2.push({ ny, nx });
		}
	}
	return -1;
}

int main() {
	FASTIO;
	int sy = 0, sx = 0;
	cin >> N >> M >> K;
	Map = vector<vector<int>>(N, vector<int>(M));
	visited = vector<vector<int>>(N, vector<int>(M, 0));
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 3) {
				q1.push({ i, j });
				visited[i][j] = 1;
			}
			else if (Map[i][j] == 4) {
				sy = i, sx = j;
			}
		}
	}
	BFS1();
	cout << BFS2(sy, sx);

	return 0;
}