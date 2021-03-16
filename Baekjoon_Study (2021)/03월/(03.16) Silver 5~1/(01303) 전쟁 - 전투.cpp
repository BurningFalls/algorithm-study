#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
char Map[101][101];
bool visited[101][101] = { 0, };
int Wsum = 0, Bsum = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int sum;

void DFS(int y, int x, char kind) {
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
		if (Map[ny][nx] != kind) continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		sum++;
		DFS(ny, nx, kind);
	}
}

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] != 'W') continue;
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			sum = 1;
			DFS(i, j, 'W');
			Wsum += sum * sum;
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] != 'B') continue;
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			sum = 1;
			DFS(i, j, 'B');
			Bsum += sum * sum;
		}
	}
	cout << Wsum << " " << Bsum;

	return 0;
}