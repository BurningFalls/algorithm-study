#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

int N;
queue<pii> q;
int r1, c1, r2, c2;
int visited[201][201] = { 0, };
int dy[6] = { -2, -2, 0, 0, 2, 2 };
int dx[6] = { -1, 1, -2, 2, -1, 1 };

int BFS() {
	visited[r1][c1] = 1;
	q.push({ r1, c1 });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		if (y == r2 && x == c2)
			return visited[y][x];
		q.pop();
		FOR(i, 0, 5) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;
	cout << BFS() - 1;

	return 0;
}