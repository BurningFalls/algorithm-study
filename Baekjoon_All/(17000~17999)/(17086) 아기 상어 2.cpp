#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
bool Map[51][51];
int visited[51][51] = { 0, };
queue<pii> q;
int maximum = 0;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void BFS() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int vis = visited[y][x];
		maximum = max(maximum, vis - 1);
		q.pop();
		FOR(i, 0, 7) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = vis + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	BFS();
	cout << maximum;

	return 0;
}