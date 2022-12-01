#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> Map(N + 2, vector<int>(M + 2));
	vector<vector<int>> visited(N + 2, vector<int>(M + 2, 0));
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}

	queue<pii> q;
	vector<int> dy = { -1, -1, -1, 0, 0, 1, 1, 1 };
	vector<int> dx = { -1, 0, 1, -1, 1, -1, 0, 1 };
	FOR(i, 1, M + 1) {
		q.push({ 0, i });
		visited[0][i] = 1;
	}
	FOR(i, 1, N) {
		q.push({ i, M + 1 });
		visited[i][M + 1] = 1;
	}
	FOR(i, 1, N + 1) {
		q.push({ i, 0 });
		visited[i][0] = 2;
	}
	FOR(i, 1, M) {
		q.push({ N + 1, i });
		visited[N + 1][i] = 2;
	}

	bool flag = false;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 7) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == 0) continue;
			if (visited[ny][nx]) {
				if (visited[y][x] != visited[ny][nx]) {
					flag = true;
				}
				continue;
			}
			visited[ny][nx] = visited[y][x];
			q.push({ ny, nx });
		}
	}

	if (flag) {
		cout << 0;
		return 0;
	}
	
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == 1) continue;
			if (i == 1 && j == 1) continue;
			if (i == N && j == M) continue;
			bool f1 = false, f2 = false;
			FOR(k, 0, 7) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny > N + 1 || nx > M + 1) continue;
				if (visited[ny][nx] == 1) f1 = true;
				if (visited[ny][nx] == 2) f2 = true;
			}
			if (f1 && f2) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	if (flag) {
		cout << 1;
	}
	else if (!flag) {
		if (N == 1 || M == 1) {
			cout << 1;
		}
		else {
			cout << 2;
		}
	}

	return 0;
}