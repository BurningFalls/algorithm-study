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
int H, W, Sr, Sc, Fr, Fc;
bool Map[1001][1001];
int visited[1001][1001] = { 0, };

int BFS() {
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int y_start[4] = {0, H - 1, 0, 0};
	int y_end[4] = {0, H - 1, H - 1, H - 1};
	int x_start[4] = {0, 0, 0, W - 1};
	int x_end[4] = {W - 1, W - 1, 0, W - 1};
	q.push({ Sr, Sc });
	visited[Sr][Sc] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == Fr && x == Fc) {
			return visited[y][x] - 1;
		}
		FOR(k, 0, 3) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 1 || nx < 1 || ny + H - 1 > N || nx + W - 1 > M) continue;
			if (visited[ny][nx]) continue;
			bool flag = true;
			FOR(i, y_start[k], y_end[k]) {
				FOR(j, x_start[k], x_end[k]) {
					int nny = ny + i;
					int nnx = nx + j;
					if (Map[nny][nnx]) {
						flag = false;
					}
				}
			}
			if (!flag) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
	cout << BFS();

	return 0;
}