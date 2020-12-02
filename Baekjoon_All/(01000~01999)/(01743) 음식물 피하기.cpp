#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
bool Map[101][101] = { 0, };
bool visited[101][101] = { 0, };
int cnt;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans = 0;

void BFS(int sy, int sx) {
	queue<pii> q;
	cnt = 1;
	visited[sy][sx] = 1;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (!Map[ny][nx]) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
			cnt++;
		}
	}
}

int main() {
	FASTIO;
	int K;
	cin >> N >> M >> K;
	FOR(i, 1, K) {
		int y, x;
		cin >> y >> x;
		Map[y][x] = 1;
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (!Map[i][j]) continue;
			if (visited[i][j]) continue;
			BFS(i, j);
			ans = max(ans, cnt);
		}
	}
	cout << ans;

	return 0;
}