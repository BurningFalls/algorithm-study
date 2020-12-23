#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int R, C;
char Map[101][101];
int N;
int Group[101][101];
int bar[101];

void BFS(int sy, int sx, int idx) {
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	Group[sy][sx] = idx;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
			if (Map[ny][nx] == '.') continue;
			if (Group[ny][nx]) continue;
			Group[ny][nx] = idx;
			q.push({ ny, nx });
		}
	}
}

void Grouping() {
	memset(Group, 0, sizeof(Group));
	int idx = 1;
	FOR(i, 1, C) {
		if (Map[R][i] == '.') continue;
		if (Group[R][i]) continue;
		BFS(R, i, idx);
	}
	ROF(i, R, 1) {
		FOR(j, 1, C) {
			if (Map[i][j] == '.') continue;
			if (Group[i][j]) continue;
			idx++;
			BFS(i, j, idx);
		}
	}
}

void Destroy(int len, int idx) {
	if (idx == 1) {
		FOR(i, 1, C) {
			if (Map[R + 1 - len][i] == 'x') {
				Map[R + 1 - len][i] = '.';
				return;
			}
		}
	}
	else if (idx == 0) {
		ROF(i, C, 1) {
			if (Map[R + 1 - len][i] == 'x') {
				Map[R + 1 - len][i] = '.';
				return;
			}
		}
	}
}

void Gravity() {
	int min_cnt = 200;
	FOR(i, 1, C) {
		int dist = -1;
		int cnt = 0;
		ROF(j, R, 1) {
			if (Group[j][i] == 2) {
				dist = cnt;
				break;
			}
			else if (Group[j][i] == 1) {
				cnt = 0;
			}
			else if (Group[j][i] == 0) {
				cnt++;
			}
		}
		if (dist != -1)
			min_cnt = min(min_cnt, dist);
	}
	if (min_cnt == 200)
		return;
	ROF(i, R, 1) {
		FOR(j, 1, C) {
			if (Group[i][j] == 2) {
				Map[i][j] = '.';
				Map[i + min_cnt][j] = 'x';
			}
		}
	}
}

void Print() {
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cout << Map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	FASTIO;
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}
	cin >> N;
	FOR(i, 1, N) {
		cin >> bar[i];
	}
	FOR(i, 1, N) {
		Destroy(bar[i], i % 2);
		Grouping();
		Gravity();
	}
	Print();

	return 0;
}