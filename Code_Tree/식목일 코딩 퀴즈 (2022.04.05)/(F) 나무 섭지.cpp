#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 1001

int N, M;
vector<vector<char>> Map(MAX, vector<char>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<vector<int>> ghost_arrive(MAX, vector<int>(MAX, 0));
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void Ghost_BFS(queue<pii>& q) {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (ghost_arrive[ny][nx]) continue;
			ghost_arrive[ny][nx] = ghost_arrive[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

void BFS(int sy, int sx) {
	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (Map[y][x] == 'D') {
			cout << "Yes";
			exit(0);
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == '#') continue;
			if (visited[ny][nx]) continue;
			if (ghost_arrive[ny][nx] <= visited[y][x] + 1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	int posy = -1, posx = -1;
	queue<pii> ghost;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
			if (Map[i][j] == 'N') {
				posy = i; posx = j;
			}
			else if (Map[i][j] == 'G') {
				ghost.push({ i, j });
				ghost_arrive[i][j] = 1;
			}
		}
	}

	Ghost_BFS(ghost);

	BFS(posy, posx);

	cout << "No";

	return 0;
}