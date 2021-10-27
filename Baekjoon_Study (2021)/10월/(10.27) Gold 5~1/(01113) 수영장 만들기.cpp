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
char Map[51][51];
int visited[51][51] = { 0, };

int BFS(int sy, int sx, int height, int vis) {
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int sum = 0;
	visited[sy][sx] = vis;
	q.push({ sy, sx });
	bool flag = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		sum += (height - (Map[y][x] - '0'));
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) {
				flag = false;
				continue;
			}
			if (Map[ny][nx] - '0' >= height) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = vis;
			q.push({ ny, nx });
		}
	}
	if (!flag) {
		sum = 0;
	}
	else if (flag) {
		FOR(i, 1, N) {
			FOR(j, 1, M) {
				if (visited[i][j] == vis) {
					Map[i][j] = height + '0';
				}
			}
		}
	}
	return sum;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	int ans = 0;
	ROF(height, 9, 1) {
		memset(visited, 0, sizeof(visited));
		int vis = 1;
		FOR(i, 1, N) {
			FOR(j, 1, M) {
				if (Map[i][j] - '0' >= height) continue;
				if (visited[i][j]) continue;
				ans += BFS(i, j, height, vis);
				vis++;
			}
		}
	}
	cout << ans;

	return 0;
}