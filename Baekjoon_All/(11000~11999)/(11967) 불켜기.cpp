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
vector<pii> Switch[101][101];
bool Possible[101][101] = { 0, };
bool visited[101][101] = { 0, };
bool waiting[101][101] = { 0, };

int BFS() {
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	q.push({ 1, 1 });
	visited[1][1] = 1;
	Possible[1][1] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (pii sc : Switch[y][x]) {
			int ny = sc.first;
			int nx = sc.second;
			Possible[ny][nx] = 1;
			if (waiting[ny][nx] && !visited[ny][nx]) {
				waiting[ny][nx] = 0;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (visited[ny][nx]) continue;
			if (!Possible[ny][nx]) {
				waiting[ny][nx] = 1;
			}
			else if (Possible[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cnt += Possible[i][j];
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(m, 1, M) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		Switch[x][y].push_back({ a, b });
	}
	cout << BFS();

	return 0;
}