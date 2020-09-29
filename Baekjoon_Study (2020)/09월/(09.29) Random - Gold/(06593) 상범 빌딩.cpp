#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define tiii tuple<int, int, int>

int L, R, C;
char Square[32][32][32];
int visited[32][32][32];
tiii Start, End;
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 1, -1, 0, 0, 0, 0 };

int BFS() {
	queue<tiii> q;
	q.push(Start);
	visited[get<0>(Start)][get<1>(Start)][get<2>(Start)] = 1;
	while (!q.empty()) {
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();
		if (End == make_tuple(z, y, x))
			return visited[z][y][x];
		FOR(i, 0, 5) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 1 || ny < 1 || nx < 1 || nz > L || ny > R || nx > C) continue;
			if (Square[nz][ny][nx] == '#') continue;
			if (visited[nz][ny][nx]) continue;
			visited[nz][ny][nx] = visited[z][y][x] + 1;
			q.push({ nz, ny, nx });
		}
	}
	return -1;
}

int main() {
	FASTIO;
	while (true) {
		memset(visited, 0, sizeof(visited));
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		FOR(i, 1, L) {
			FOR(j, 1, R) {
				FOR(k, 1, C) {
					cin >> Square[i][j][k];
					if (Square[i][j][k] == 'S')
						Start = { i, j, k };
					else if (Square[i][j][k] == 'E')
						End = { i, j, k };
				}
			}
		}
		int temp = BFS();
		if (temp == -1)
			cout << "Trapped!";
		else
			cout << "Escaped in " << temp - 1 << " minute(s).";
		cout << "\n";
	}

	return 0;
}