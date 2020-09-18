#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
char arr[1002][1002];
vector<pair<int, int>> v[1001][1001];
bool visited[1001][1001] = { 0, };

void Set_Graph(int y, int x) {
	int ny, nx;
	if (arr[y][x] == 'D') {
		ny = y + 1;
		nx = x;
		if (ny > N)
			return;
		v[y][x].push_back({ ny, nx });
		v[ny][nx].push_back({ y, x });
	}
	else if (arr[y][x] == 'U') {
		ny = y - 1;
		nx = x;
		if (ny < 1)
			return;
		v[y][x].push_back({ ny, nx });
		v[ny][nx].push_back({ y, x });
	}
	else if (arr[y][x] == 'L') {
		ny = y;
		nx = x - 1;
		if (nx < 1)
			return;
		v[y][x].push_back({ ny, nx });
		v[ny][nx].push_back({ y, x });
	}
	else if (arr[y][x] == 'R') {
		ny = y;
		nx = x + 1;
		if (nx > M)
			return;
		v[y][x].push_back({ ny, nx });
		v[ny][nx].push_back({ y, x });
	}
}

void DFS(int y, int x) {
	visited[y][x] = 1;
	int len = v[y][x].size();
	FOR(i, 0, len - 1) {
		int ny = v[y][x][i].first;
		int nx = v[y][x][i].second;
		if (visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, N)
		FOR(j, 1, M)
			Set_Graph(i, j);
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (visited[i][j]) continue;
			cnt++;
			DFS(i, j);
		}
	}
	cout << cnt;

	return 0;
}