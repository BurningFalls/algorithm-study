#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int arr[31][31];
int arr2[31][31];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool changed[31][31] = { 0, };
int ch_arr[31][31];

bool BFS(int sy, int sx) {
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			ch_arr[i][j] = arr[i][j];
		}
	}
	bool visited[31][31] = { 0, };
	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	int num = arr[sy][sx];
	int ch_num = arr2[sy][sx];
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		ch_arr[y][x] = ch_num;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (arr[ny][nx] != num) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (ch_arr[i][j] != arr2[i][j])
				return false;
		}
	}
	return true;
}

bool is_Possible() {
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (!changed[i][j]) continue;
			return BFS(i, j);
		}
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
	int ch_cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr2[i][j];
			if (arr2[i][j] != arr[i][j]) {
				changed[i][j] = 1;
				ch_cnt++;
			}
		}
	}
	if (ch_cnt == 0)
		cout << "YES";
	else {
		cout << (is_Possible() ? "YES" : "NO");
	}

	return 0;
}