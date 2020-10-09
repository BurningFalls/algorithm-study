#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char Map[51][51];
int visited[51][51][1 << 6] = { 0, };
queue<pair<pair<int, int>, int>> q;
int dy[4] = { -1, 1 ,0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans = -1;

int BFS() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int key = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int new_key = key;
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == '#') continue;
			if (Map[ny][nx] == '1')
				return visited[y][x][key] + 1;
			if (visited[ny][nx][new_key]) continue;
			if (Map[ny][nx] >= 'a' && Map[ny][nx] <= 'f')
				new_key |= 1 << (Map[ny][nx] - 'a');
			if (Map[ny][nx] >= 'A' && Map[ny][nx] <= 'F')
				if (!(key & 1 << (Map[ny][nx] - 'A'))) continue;
			visited[ny][nx][new_key] = visited[y][x][key] + 1;
			q.push({ { ny, nx }, new_key });
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
			if (Map[i][j] == '0') {
				q.push({ { i, j }, 0 });
				visited[i][j][0] = 1;
			}
		}
	}
	cout << BFS() - 1;

	return 0;
}