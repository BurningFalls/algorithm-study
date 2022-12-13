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

struct NODE {
	int y;
	int x;
	int vis;
};

int W, H;
vector<vector<char>> Map;
vector<vector<int>> visited;
vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };
int sy, sx;
int mini;

void Move() {
	queue<NODE> q;
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			if (Map[i][j] == '*') {
				visited[i][j] = -1;
				q.push({ i, j, -1 });
			}
		}
	}
	visited[sy][sx] = 1;
	q.push({ sy, sx, 1 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int vis = q.front().vis;
		q.pop();
		if (vis > 0 && (y == 0 || y == H - 1 || x == 0 || x == W - 1)) {
			mini = min(mini, vis);
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (Map[ny][nx] == '#') continue;
			if (vis == -1) {
				if (visited[ny][nx] == -1) continue;
				visited[ny][nx] = -1;
				q.push({ ny, nx, -1 });
			}
			else if (vis > 0) {
				if (visited[ny][nx] > 0) continue;
				if (visited[ny][nx] == -1) continue;
				visited[ny][nx] = vis + 1;
				q.push({ ny, nx, visited[ny][nx] });
			}
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> W >> H;
		Map = vector<vector<char>>(H, vector<char>(W));
		visited = vector<vector<int>>(H, vector<int>(W, 0));
		mini = INF;
		FOR(i, 0, H - 1) {
			FOR(j, 0, W - 1) {
				cin >> Map[i][j];
				if (Map[i][j] == '@') {
					sy = i;
					sx = j;
				}
			}
		}
		Move();
		if (mini == INF) {
			cout << "IMPOSSIBLE";
		}
		else {
			cout << mini;
		}
		cout << "\n";
	}

	return 0;
}