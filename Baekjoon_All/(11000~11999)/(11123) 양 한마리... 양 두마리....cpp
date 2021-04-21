#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int H, W;
char arr[102][102];
bool visited[102][102];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int sy, int sx) {
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
			if (ny < 1 || nx < 1 || ny > H || nx > W) continue;
			if (arr[ny][nx] == '.') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> H >> W;
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				cin >> arr[i][j];
			}
		}
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				if (arr[i][j] == '.') continue;
				if (visited[i][j]) continue;
				BFS(i, j);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}


	return 0;
}