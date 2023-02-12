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

int N, M;
int hy, hx, ey, ex;
vector<vector<char>> Map;
vector<vector<int>> visited;
vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };
set<pii> posp;

int BFS(int sy, int sx) {
	visited = vector<vector<int>>(N, vector<int>(M, 0));
	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (Map[ny][nx] == 'X') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	int svis = visited[hy][hx];
	if (svis == 0) return 0;

	int cnt = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			if (Map[i][j] != 'P') continue;
			if (visited[i][j] == 0) continue;
			cnt += (svis >= visited[i][j]);
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> M;
	Map = vector<vector<char>>(N, vector<char>(M));
	vector<pii> exit;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 'H') {
				hy = i, hx = j;
			}
			else if (Map[i][j] == '#') {
				exit.push_back({ i, j });
			}
		}
	}

	int maxi = 0;
	FOR(i, 0, LEN(exit) - 1) {
		int ey = exit[i].first;
		int ex = exit[i].second;
		if (ey < 0 || ex < 0 || ey >= N || ex >= M) continue;
		maxi = max(maxi, BFS(ey, ex));
	}

	cout << maxi;

	return 0;
}