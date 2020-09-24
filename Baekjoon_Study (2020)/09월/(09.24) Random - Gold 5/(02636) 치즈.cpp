#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
bool arr[102][102];
bool visited[102][102];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int cnt = 0;

void BFS() {
	queue<pii> q;
	memset(visited, 0, sizeof(visited));
	q.push({ 0, 0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > N + 1 || nx > M + 1) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] == 1) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

bool Check(int y, int x) {
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (visited[ny][nx] == 1)
			return true;
	}
	return false;
}

void Melt() {
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (arr[i][j] == 0) continue;
			if (!Check(i, j)) continue;
			arr[i][j] = 0;
			cnt--;
		}
	}
}

int main() {
	FASTIO;
	int ans = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				cnt++;
		}
	}
	int temp = 0;
	while (cnt > 0) {
		temp = cnt;
		ans++;
		BFS();
		Melt();
	}
	cout << ans << "\n" << temp;

	return 0;
}