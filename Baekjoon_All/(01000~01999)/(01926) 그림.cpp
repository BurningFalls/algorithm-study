#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
bool Map[501][501];
bool visited[501][501] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int cnt;

void BFS(int sy, int sx) {
	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
			if (Map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	int maximum = 0;
	int picture_cnt = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == 0) continue;
			if (visited[i][j]) continue;
			cnt = 0;
			picture_cnt++;
			BFS(i, j);
			maximum = max(maximum, cnt);
		}
	}
	cout << picture_cnt << "\n" << maximum;

	return 0;
}