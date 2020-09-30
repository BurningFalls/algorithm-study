#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int arr[302][302];
int ch_arr[302][302];
bool visited[302][302];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ice_cnt = 0;
int group_cnt;

void Ch(int y, int x) {
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (arr[ny][nx] == 0)
			ch_arr[y][x]--;
	}
	if (ch_arr[y][x] <= 0) {
		ch_arr[y][x] = 0;
		ice_cnt--;
	}
}

void BFS(int a, int b) {
	queue<pii> q;
	q.push({ a, b });
	visited[a][b] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (arr[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

void is_Divide() {
	memset(visited, 0, sizeof(visited));
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (arr[i][j] == 0) continue;
			if (visited[i][j]) continue;
			group_cnt++;
			BFS(i, j);
		}
	}
}

int main() {
	FASTIO;
	int year = 1;
	bool flag = false;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
			ch_arr[i][j] = arr[i][j];
			if (arr[i][j] != 0)
				ice_cnt++;
		}
	}
	while (ice_cnt > 0) {
		group_cnt = 0;
		FOR(i, 1, N) {
			FOR(j, 1, M) {
				if (arr[i][j] != 0) {
					Ch(i, j);
				}
			}
		}
		FOR(i, 1, N) {
			FOR(j, 1, M) {
				arr[i][j] = ch_arr[i][j];
			}
		}
		is_Divide();
		if (group_cnt >= 2) {
			flag = true;
			break;
		}
		year++;
	}
	if (flag)
		cout << year;
	else
		cout << 0;

	return 0;
}