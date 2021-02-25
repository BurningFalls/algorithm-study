#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

char Map[10][10];
bool pos[10][10] = { 0, };
bool wall[10][10] = { 0, };
int cnt = 0;
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
queue<pii> q;

int main() {
	FASTIO;
	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			cin >> Map[i][j];
			if (Map[i][j] == '#') {
				cnt++;
			}
		}
	}
	bool flag = true;
	q.push({ 8, 1 });
	while (cnt > 0) {
		memset(pos, 0, sizeof(pos));
		memset(wall, 0, sizeof(wall));
		FOR(i, 1, 8) {
			FOR(j, 1, 8) {
				if (Map[i][j] == '#')
					wall[i][j] = 1;
			}
		}
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			FOR(i, 0, 8) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 1 || nx < 1 || ny > 8 || nx > 8) continue;
				pos[ny][nx] = 1;
			}
		}
		ROF(i, 8, 1) {
			FOR(j, 1, 8) {
				if (wall[i][j]) {
					if (i != 8)
						wall[i + 1][j] = 1;
					else if (i == 8)
						cnt--;
				}
				if (Map[i][j] == '#') {
					if (i != 8)
						Map[i + 1][j] = '#';
					Map[i][j] = '.';
				}
			}
		}
		FOR(i, 1, 8) {
			FOR(j, 1, 8) {
				if (pos[i][j] && !wall[i][j]) {
					q.push({ i, j });
				}
			}
		}
		if (q.empty()) {
			flag = false;
			break;
		}
	}
	cout << flag;

	return 0;
}