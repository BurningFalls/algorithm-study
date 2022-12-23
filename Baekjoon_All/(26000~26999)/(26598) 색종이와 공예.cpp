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
#define MAX 1001

int N, M;
vector<vector<char>> Map(MAX, vector<char>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };

bool BFS(int sy, int sx) {
	queue<pii> q;
	char c = Map[sy][sx];
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	int miny = N - 1, maxy = 0;
	int minx = M - 1, maxx = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		miny = min(miny, y); maxy = max(maxy, y);
		minx = min(minx, x); maxx = max(maxx, x);
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (Map[ny][nx] != c) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	bool flag = true;
	FOR(i, miny, maxy) {
		FOR(j, minx, maxx) {
			if (Map[i][j] != c) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	return flag;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}

	bool flag = true;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			flag &= BFS(i, j);
			if (!flag) break;
		}
		if (!flag) break;
	}
	cout << (flag ? "dd" : "BaboBabo");

	return 0;
}