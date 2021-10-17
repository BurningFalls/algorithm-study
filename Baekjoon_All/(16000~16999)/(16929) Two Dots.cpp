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
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int N, M;
vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };
vector<vector<char>> Map(51, vector<char>(51));
vvi visited(51, vi(51, 0));

bool DFS(char c, int y, int x, int py, int px) {
	visited[y][x] = 1;
	bool flag = false;
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (ny == py && nx == px) continue;
		if (Map[ny][nx] != c) continue;
		if (visited[ny][nx]) {
			flag = true;
		}
		else {
			flag |= DFS(c, ny, nx, y, x);
		}
	}
	return flag;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}
	bool flag = false;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			if (visited[i][j]) continue;
			flag |= DFS(Map[i][j], i, j, -1, -1);
		}
	}
	cout << (flag ? "Yes" : "No");

	return 0;
}