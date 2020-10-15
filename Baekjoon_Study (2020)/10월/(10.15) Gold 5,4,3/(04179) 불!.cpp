#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int R, C;
char Map[1001][1001];
queue<pii> Jq, Fq;
int visited[1001][1001] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void F_BFS() {
	int len = Fq.size();
	FOR(i, 1, len) {
		int y = Fq.front().first;
		int x = Fq.front().second;
		Fq.pop();
		FOR(j, 0, 3) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
			if (visited[ny][nx] == 1) continue;
			visited[ny][nx] = 1;
			Fq.push({ ny, nx });
		}
	}
}

int J_BFS() {
	bool flag = false;
	int len = Jq.size();
	FOR(i, 1, len) {
		int y = Jq.front().first;
		int x = Jq.front().second;
		Jq.pop();
		if (y == 1 || y == R || x == 1 || x == C)
			return 2;
		FOR(j, 0, 3) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
			if (visited[ny][nx] == 1 || visited[ny][nx] == 2) continue;
			visited[ny][nx] = 2;
			Jq.push({ ny, nx });
			flag = true;
		}
	}
	if (flag)
		return 1;
	return 0;
}

int main() {
	FASTIO;
	int t = 0;
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
			if (Map[i][j] == 'J') {
				Jq.push({ i, j });
				visited[i][j] = 2;
			}
			else if (Map[i][j] == 'F') {
				Fq.push({ i, j });
				visited[i][j] = 1;
			}
			else if (Map[i][j] == '#') {
				visited[i][j] = 1;
			}
		}
	}
	int flag = 0;
	while (true) {
		t++;
		F_BFS();
		flag = J_BFS();
		if (flag == 0 || flag == 2)
			break;
	}
	if (flag == 0)
		cout << "IMPOSSIBLE";
	else
		cout << t;

	return 0;
}