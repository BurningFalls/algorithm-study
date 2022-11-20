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
#define MAX 3001

int N, M, K;
vector<vector<int>> Map(MAX, vector<int>(MAX, 0));

void BFS() {
	queue<pii> q;
	vector<int> dy = { -1, 1, 0, 0 };
	vector<int> dx = { 0, 0, -1, 1 };
	q.push({ 1, 1 });
	Map[1][1] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] != 0) continue;
			Map[ny][nx] = Map[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	vector<int> dy = { -1, 1, 1, -1 };
	vector<int> dx = { 1, 1, -1, -1 };
	FOR(i, 1, K) {
		int r, c, d;
		cin >> r >> c >> d;
		if (d == 0) {
			Map[r][c] = -1;
			continue;
		}
		vector<int> gy = { r - d, r, r + d, r };
		vector<int> gx = { c, c + d, c, c - d };
		int y = r, x = c - d;
		FOR(i, 0, 3) {
			while (y != gy[i] || x != gx[i]) {
				if (y >= 1 && x >= 1 && y <= N && x <= M) {
					Map[y][x] = -1;
				}
				y += dy[i];
				x += dx[i];
			}
		}
	}

	BFS();

	if (Map[N][M] == 0) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		cout << Map[N][M] - 1;
	}

	return 0;
}