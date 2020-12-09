#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int arr[51][51];
int visited[51][51] = { 0, };
int AREA[2501] = { 0, };
int room_cnt = 0;
int area;
int max_area = 0, max_area2 = 0;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void BFS(int sy, int sx, int idx) {
	queue<pii> q;
	visited[sy][sx] = idx;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		area++;
		FOR(i, 0, 3) {
			if (arr[y][x] & (1 << i)) continue;
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = idx;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (visited[i][j]) continue;
			area = 0;
			room_cnt++;
			BFS(i, j, room_cnt);
			AREA[room_cnt] = area;
			max_area = max(max_area, area);
		}
	}
	cout << room_cnt << "\n" << max_area << "\n";
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			FOR(k, 0, 3) {
				if (!(arr[i][j] & (1 << k))) continue;
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
				if (visited[i][j] == visited[ny][nx]) continue;
				max_area2 = max(max_area2, AREA[visited[i][j]] + AREA[visited[ny][nx]]);
			}
		}
	}
	cout << max_area2;

	return 0;
}