#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char arr[601][601];
bool visited[601][601] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int cnt = 0;

void BFS(int sy, int sx) {
	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (arr[y][x] == 'P')
			cnt++;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (arr[ny][nx] == 'X') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	int sy = 0, sx = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') {
				sy = i; sx = j;
			}
		}
	}

	BFS(sy, sx);
	if (cnt == 0)
		cout << "TT";
	else
		cout << cnt;

	return 0;
}