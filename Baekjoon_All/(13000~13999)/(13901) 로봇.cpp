#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int R, C;
int K;
char Map[1001][1001];
bool visited[1001][1001] = { 0, };
int dir[4];
int py, px;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int dm_cnt = 0;

void Move(int sr, int sc) {
	py = sr, px = sc;
	visited[py][px] = 1;
	int dir_node = 0;
	while (true) {
		int ny = py + dy[dir[dir_node]];
		int nx = px + dx[dir[dir_node]];
		if ((ny < 0 || nx < 0 || ny >= R || nx >= C) ||
			(visited[ny][nx]) || (Map[ny][nx] == 'x')) {
			dir_node = (dir_node + 1) % 4;
			dm_cnt++;
			if (dm_cnt == 4)
				break;
			continue;
		}
		dm_cnt = 0;
		visited[ny][nx] = 1;
		py = ny, px = nx;
	}

}

int main() {
	FASTIO;
	cin >> R >> C;
	FOR(i, 0, R - 1) {
		FOR(j, 0, C - 1) {
			Map[i][j] = '*';
		}
	}
	cin >> K;
	FOR(i, 1, K) {
		int br, bc;
		cin >> br >> bc;
		Map[br][bc] = 'x';
	}
	int sr, sc;
	cin >> sr >> sc;
	FOR(i, 0, 3) {
		int d;
		cin >> d;
		dir[i] = d - 1;
	}
	Move(sr, sc);
	cout << py << " " << px;

	return 0;
}