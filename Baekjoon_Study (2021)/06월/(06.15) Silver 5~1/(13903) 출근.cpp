#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int R, C, N;
bool Map[1001][1001];
int visited[1001][1001] = { 0, };
int dy[11];
int dx[11];

int BFS() {
	queue<pii> q;
	FOR(i, 1, C) {
		if (Map[1][i] == 0) continue;
		q.push({ 1, i });
		visited[1][i] = 1;
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == R)
			return visited[y][x];
		FOR(i, 1, N) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
			if (Map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}
	cin >> N;
	FOR(i, 1, N) {
		cin >> dy[i] >> dx[i];
	}

	cout << BFS() - 1;


	return 0;
}