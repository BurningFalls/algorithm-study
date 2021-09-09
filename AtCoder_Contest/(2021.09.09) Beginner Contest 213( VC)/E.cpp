#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int H, W;
char arr[501][501];
bool visited[501][501][2] = { 0, };
priority_queue<pair<int, pii>> pq;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS() {
	pq.push({ 0, { 1, 1 } });
	visited[1][1][0] = 1;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (y == H && x == W)
			return cost;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > H || nx > W) continue;
			if (arr[ny][nx] == '#') continue;
			if (visited[ny][nx][0]) continue;
			visited[ny][nx][0] = 1;
			pq.push({ -cost, { ny, nx } });
		}
		FOR(i, -2, 2) {
			FOR(j, -2, 2) {
				if (i == -2 && j == -2) continue;
				if (i == -2 && j == 2) continue;
				if (i == 2 && j == -2) continue;
				if (i == 2 && j == 2) continue;
				if (i == 0 && j == 0) continue;
				int ny = y + i;
				int nx = x + j;
				if (ny < 1 || nx < 1 || ny > H || nx > W) continue;
				if (arr[ny][nx] == '.') continue;
				if (visited[ny][nx][1]) continue;
				visited[ny][nx][1] = 1;
				pq.push({ -(cost + 1), { ny, nx } });
			}
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> H >> W;
	FOR(i, 1, H) {
		FOR(j, 1, W) {
			cin >> arr[i][j];
		}
	}
	cout << BFS();

	return 0;
}