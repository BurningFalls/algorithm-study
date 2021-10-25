#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, M;
int Map[21][21];
int visited[21][21];

pii BFS(int sy, int sx, int vis) {
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	q.push({ sy, sx });
	visited[sy][sx] = vis;
	int color = Map[sy][sx];
	int cnt = 0;
	int zero_cnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		if (Map[y][x] == 0) {
			zero_cnt++;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (Map[ny][nx] == -1) continue;
			if ((visited[ny][nx] != vis && Map[ny][nx] == 0) || (!visited[ny][nx] && Map[ny][nx] == color)) {
				visited[ny][nx] = vis;
				q.push({ ny, nx });
			}
		}
	}
	return { cnt, zero_cnt };
}

void Gravity() {
	int tmp[21][21];
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			tmp[i][j] = Map[i][j];
			Map[i][j] = -2;
		}
	}
	FOR(j, 1, N) {
		int ground = N;
		int idx = N;
		while (ground >= 1 && idx >= 1) {
			if (tmp[idx][j] == -1) {
				Map[idx][j] = -1;
				ground = idx - 1;
				idx--;
			}
			else if (tmp[idx][j] == -2) {
				idx--;
			}
			else {
				Map[ground][j] = tmp[idx][j];
				ground--;
				idx--;
			}
		}
	}
}

void Rotate() {
	int tmp[21][21];
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			tmp[N + 1 - j][i] = Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			Map[i][j] = tmp[i][j];
		}
	}
}

int main() {
	FASTIO;
	int ans = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	while (true) {
		memset(visited, 0, sizeof(visited));
		int idx = 0;
		int max_cnt = 0;
		int zero_max = 0;
		int vis_max = 0;
		int col_max = 0;
		int row_max = 0;
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (Map[i][j] < 1) continue;
				if (visited[i][j]) continue;
				idx++;
				pii cnt = BFS(i, j, idx);
				if (max_cnt < cnt.first) {
					max_cnt = cnt.first;
					zero_max = cnt.second;
					vis_max = idx;
					col_max = i;
					row_max = j;
				}
				else if (max_cnt == cnt.first) {
					if (zero_max < cnt.second) {
						zero_max = cnt.second;
						vis_max = idx;
						col_max = i;
						row_max = j;
					}
					else if (zero_max == cnt.second) {
						if (col_max < i) {
							vis_max = idx;
							col_max = i;
							row_max = j;
						}
						else if (col_max == i) {
							if (row_max < j) {
								vis_max = idx;
								row_max = j;
							}
						}
					}
				}
			}
		}
		if (max_cnt <= 1)
			break;
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (Map[i][j] != 0 && visited[i][j] == vis_max) {
					memset(visited, 0, sizeof(visited));
					BFS(i, j, vis_max);
					i = N;
					break;
				}
			}
		}
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (visited[i][j] == vis_max) {
					Map[i][j] = -2;
				}
			}
		}
		ans += max_cnt * max_cnt;
		Gravity();
		Rotate();
		Gravity();
	}
	cout << ans;

	return 0;
}