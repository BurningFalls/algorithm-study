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

void BFS(pii goal, int N, int M, vector<vector<int>>& Map, vector<vector<int>>& visited) {
	queue<pii> q;
	vector<int> dy = { -1, 1, 0, 0 };
	vector<int> dx = { 0, 0, -1, 1 };
	q.push(goal);
	visited[goal.first][goal.second] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] != -1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> Map(N, vector<int>(M));
	vector<vector<int>> visited(N, vector<int>(M, -1));
	pii goal;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				goal = { i, j };
			}
			else if (Map[i][j] == 0) {
				visited[i][j] = 0;
			}
		}
	}
	BFS(goal, N, M, Map, visited);
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}