#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, M;
char Map[21][21];
int vill_cnt = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS(int A, int B) {
	queue<pii> q;
	int cnt = 0;
	int visited[21][21] = { 0, };
	q.push({ A / M, A % M });
	q.push({ B / M, B % M });
	visited[A / M][A % M] = 1;
	visited[B / M][B % M] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (Map[ny][nx] == '1') {
				cnt++;
				if (cnt == vill_cnt) {
					return visited[y][x];
				}
			}
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return INF;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == '1')
				vill_cnt++;
		}
	}
	int ans = INF;
	FOR(i, 0, N* M - 1) {
		if (Map[i / M][i % M] == '1') continue;
		FOR(j, i + 1, N * M - 1) {
			if (Map[j / M][j % M] == '1') continue;
			ans = min(ans, BFS(i, j));
		}
	}
	cout << ans;

	return 0;
}