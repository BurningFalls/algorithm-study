#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int M, N;
bool arr[251][251];
bool visited[251][251];
int ans = 0;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void BFS(int sy, int sx) {
	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 7) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > M || nx > N) continue;
			if (!arr[ny][nx]) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}

}

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(i, 1, M) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, M) {
		FOR(j, 1, N) {
			if (!arr[i][j]) continue;
			if (visited[i][j]) continue;
			ans++;
			BFS(i, j);
		}
	}
	cout << ans;

	return 0;
}