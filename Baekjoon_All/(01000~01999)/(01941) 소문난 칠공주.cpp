#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[7][7];
int chosen[7];
int ans = 0;

bool is_Connect() {
	bool tMap[7][7] = { 0, };
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	bool visited[7][7] = { 0, };
	queue<pii> q;
	FOR(i, 0, 6) {
		int t = chosen[i];
		int y = t / 5;
		int x = t % 5;
		tMap[y][x] = 1;
		if (i == 0) {
			q.push({ y, x });
			visited[y][x] = 1;
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > 4 || nx > 4) continue;
			if (visited[ny][nx]) continue;
			if (tMap[ny][nx]) {
				q.push({ ny, nx });
				visited[ny][nx] = 1;
			}
		}
	}
	if (cnt == 7)
		return true;
	return false;
}

void DFS(int node, int cnt, int cnt_s) {
	if (cnt - cnt_s > 3)
		return;
	if (cnt == 7) {
		if (is_Connect())
			ans++;
		return;
	}
	FOR(i, node, 24) {
		chosen[cnt] = i;
		int y = i / 5;
		int x = i % 5;
		if (Map[y][x] == 'S')
			DFS(i + 1, cnt + 1, cnt_s + 1);
		else
			DFS(i + 1, cnt + 1, cnt_s);
	}
}

int main() {
	FASTIO;
	FOR(i, 0, 4) FOR(j, 0, 4)
		cin >> Map[i][j];
	DFS(0, 0, 0);
	cout << ans;

	return 0;
}