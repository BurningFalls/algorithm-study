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

int N;
vector<vector<char>> Map(1002, vector<char>(1002));
vector<vector<int>> Group(1002, vector<int>(1002, 0));

void Setting() {
	Map[0][0] = '.';
	Map[0][1] = '.';
	Map[1][0] = '.';
	Group[0][0] = -1;
	Group[0][1] = -1;
	Group[1][0] = -1;
	Group[1][1] = -1;

	Map[N][N + 1] = '.';
	Map[N + 1][N] = '.';
	Map[N + 1][N + 1] = '.';
	Group[N][N] = -1;
	Group[N][N + 1] = -1;
	Group[N + 1][N] = -1;
	Group[N + 1][N + 1] = -1;

	FOR(i, 2, N + 1) {
		Map[0][i] = 'a';
		Group[0][i] = 0;
		Map[i][0] = 'b';
		Group[i][0] = 1;
	}
	FOR(i, 0, N - 1) {
		Map[i][N + 1] = 'a';
		Group[i][N + 1] = 0;
		Map[N + 1][i] = 'b';
		Group[N + 1][i] = 1;
	}
}

void BFS1(int sy, int sx, int gidx) {
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	q.push({ sy, sx });
	Group[sy][sx] = gidx;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (Map[ny][nx] != Map[y][x]) continue;
			if (Group[ny][nx] != 0) continue;
			Group[ny][nx] = gidx;
			q.push({ ny, nx });
		}
	}
}

int BFS2(int sy, int sx, vector<set<int>>& Edge, vector<vector<bool>>& visited) {
	queue<pii> q;
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int cnt = 0;
	visited[sy][sx] = 1;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		FOR(i, 0, 7) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > N + 1 || nx > N + 1) continue;
			if (Group[ny][nx] == -1) continue;
			if (Group[ny][nx] != Group[y][x]) {
				Edge[Group[y][x]].insert(Group[ny][nx]);
			}
			else {
				if (visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
	return cnt;
}

void DT(vector<int>& Weight, vector<set<int>>& Edge, vector<int>& dist) {
	PQ<pii> pq;
	dist[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (auto next : Edge[cur]) {
			if (dist[next] > dist[cur] + Weight[next]) {
				dist[next] = dist[cur] + Weight[next];
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	Setting();

	int gidx = 1;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Group[i][j] != 0) continue;
			gidx++;
			BFS1(i, j, gidx);
		}
	}

	vector<int> Weight(gidx + 1, 0);
	vector<set<int>> Edge(gidx + 1, set<int>());
	vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, 0));
	FOR(i, 0, N + 1) {
		FOR(j, 0, N + 1) {
			if (Group[i][j] == -1) continue;
			if (visited[i][j]) continue;
			int w = BFS2(i, j, Edge, visited);
			if (Group[i][j] >= 2) {
				Weight[Group[i][j]] = w;
			}
		}
	}

	vector<int> Dist(gidx + 1, INF);
	DT(Weight, Edge, Dist);

	cout << Dist[1];

	return 0;
}