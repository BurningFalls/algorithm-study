#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, M;
int Map[21][21];
bool visited[21][21] = { 0, };

int BFS(int sy, int sx) {
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	int cnt = 0;
	bool flag = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (Map[ny][nx] == 1) continue;
			if (Map[ny][nx] == 0) {
				flag = false;
			}
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	return (flag ? cnt : 0);
}

int Check() {
	memset(visited, 0, sizeof(visited));
	int sum = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			if (visited[i][j]) continue;
			if (Map[i][j] != 2) continue;
			sum += BFS(i, j);
		}
	}
	return sum;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}
	int maxi = 0;
	FOR(i, 0, N * M - 1) {
		int ay = i / M;
		int ax = i % M;
		if (Map[ay][ax] != 0) continue;
		Map[ay][ax] = 1;
		FOR(j, i + 1, N * M - 1) {
			int by = j / M;
			int bx = j % M;
			if (Map[by][bx] != 0) continue;
			Map[by][bx] = 1;
			maxi = max(maxi, Check());
			Map[by][bx] = 0;
		}
		Map[ay][ax] = 0;
	}
	cout << maxi;

	return 0;
}