#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int visited[11][10] = { 0, };
int R1, C1, R2, C2;
int dy[8] = { -2, -3, -3, -2, 2, 3, 3, 2 };
int dx[8] = { -3, -2, 2, 3, 3, 2, -2, -3 };
vector<pii> v[8];

bool Check(int y, int x, int d) {
	FOR(i, 0, 1) {
		int ny = y + v[d][i].first;
		int nx = x + v[d][i].second;
		if (ny == R2 && nx == C2)
			return false;
	}
	return true;
}

int BFS() {
	queue<pii> q;
	q.push({ R1, C1 });
	visited[R1][C1] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == R2 && x == C2)
			return visited[y][x];
		FOR(i, 0, 7) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > 10 || nx > 9) continue;
			if (visited[ny][nx]) continue;
			if (!Check(y, x, i)) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return 0;
}

int main() {
	FASTIO;
	v[0].push_back({ -1, -2 });
	v[0].push_back({ 0, -1 });
	v[1].push_back({ -2, -1 });
	v[1].push_back({ -1, 0 });
	v[2].push_back({ -2, 1 });
	v[2].push_back({ -1, 0 });
	v[3].push_back({ -1, 2 });
	v[3].push_back({ 0, 1 });
	v[4].push_back({ 1, 2 });
	v[4].push_back({ 0, 1 });
	v[5].push_back({ 2, 1 });
	v[5].push_back({ 1, 0 });
	v[6].push_back({ 2, -1 });
	v[6].push_back({ 1, 0 });
	v[7].push_back({ 1, -2 });
	v[7].push_back({ 0, -1 });

	cin >> R1 >> C1;
	cin >> R2 >> C2;
	R1 += 1;
	C1 += 1;
	R2 += 1;
	C2 += 1;
	cout << BFS() - 1;

	return 0;
}