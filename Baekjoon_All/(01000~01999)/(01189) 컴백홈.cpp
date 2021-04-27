#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int R, C, K;
int visited[7][7] = { 0, };
char Map[7][7];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans = 0;

void DFS(int y, int x) {
	if (y == 1 && x == C) {
		if (visited[y][x] == K)
			ans++;
		return;
	}
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
		if (Map[ny][nx] == 'T') continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = visited[y][x] + 1;
		DFS(ny, nx);
		visited[ny][nx] = 0;
	}
}

int main() {
	FASTIO;
	cin >> R >> C >> K;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}
	visited[R][1] = 1;
	DFS(R, 1);
	cout << ans;

	return 0;
}