#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N;
bool arr[11][11];
int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { -1, 1, -1, 1 };
bool visited[11][11] = { 0, };
bool using_visited[11][11];
int cnt;
int ans1 = 0, ans2 = 0;
int last_y, last_x;

vector<pair<int, int>> Mark(int y, int x) {
	int ty, tx;
	vector<pair<int, int>> ans;
	using_visited[y][x] = 1;
	ans.push_back({ y, x });
	ty = y, tx = x;
	while (ty <= N - 1 && tx <= N - 1) {
		ty++;
		tx++;
		if (using_visited[ty][tx] == 1) continue;
		using_visited[ty][tx] = 1;
		ans.push_back({ ty, tx });
	}
	ty = y, tx = x;
	while (ty <= N - 1 && tx >= 2) {
		ty++;
		tx--;
		if (using_visited[ty][tx] == 1) continue;
		using_visited[ty][tx] = 1;
		ans.push_back({ ty, tx });
	}
	ty = y, tx = x;
	while (ty >= 2 && tx <= N - 1) {
		ty--;
		tx++;
		if (using_visited[ty][tx] == 1) continue;
		using_visited[ty][tx] = 1;
		ans.push_back({ ty, tx });
	}
	ty = y, tx = x;
	while (ty >= 2 && tx >= 2) {
		ty--;
		tx--;
		if (using_visited[ty][tx] == 1) continue;
		using_visited[ty][tx] = 1;
		ans.push_back({ ty, tx });
	}
	return ans;
}

void Reverse(vector<pair<int, int>> ch) {
	int len = ch.size();
	FOR(i, 0, len - 1) {
		using_visited[ch[i].first][ch[i].second] = 0;
	}
}

void DFS(int y, int x) {
	if (y == last_y && x == last_x) {
		ans1 = max(ans1, cnt);
		return;
	}
	FOR(i, y, N) {
		FOR(j, 1, N) {
			if (i == y && j <= x) continue;
			if (using_visited[i][j]) continue;
			vector<pair<int, int>> ch;
			ch = Mark(i, j);
			cnt++;
			DFS(i, j);
			Reverse(ch);
			cnt--;
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
			if ((i + j) % 2 == 1)
				visited[i][j] = 1;
			else
				visited[i][j] = !arr[i][j];
			if (visited[i][j] == 0) {
				last_y = i;
				last_x = j;
			}
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (visited[i][j]) continue;
			cnt = 1;
			FOR(y, 1, N) {
				FOR(x, 1, N) {
					using_visited[y][x] = visited[y][x];
				}
			}
			Mark(i, j);
			DFS(i, j);
		}
	}
	ans2 = ans1;
	ans1 = 0;

	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if ((i + j) % 2 == 0)
				visited[i][j] = 1;
			else
				visited[i][j] = !arr[i][j];
			if (visited[i][j] == 0) {
				last_y = i;
				last_x = j;
			}
		}
	}

	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (visited[i][j]) continue;
			cnt = 1;
			FOR(y, 1, N) {
				FOR(x, 1, N) {
					using_visited[y][x] = visited[y][x];
				}
			}
			Mark(i, j);
			DFS(i, j);
		}
	}
	cout << ans1 + ans2;

	return 0;
}