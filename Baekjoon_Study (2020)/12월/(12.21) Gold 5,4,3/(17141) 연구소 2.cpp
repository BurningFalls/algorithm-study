#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, M;
int arr[51][51];
int visited[51][51] = { 0, };
vector<pii> v;
int virus_cnt;
int ans[11];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int min_time = INF;
int zero_cnt = 0;

int BFS() {
	queue<pii> q;
	memset(visited, 0, sizeof(visited));
	FOR(i, 0, M - 1) {
		int y = v[ans[i]].first;
		int x = v[ans[i]].second;
		q.push({ y, x });
		visited[y][x] = 1;
	}
	int max_visited = 0;
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		max_visited = max(max_visited, visited[y][x] - 1);
		cnt++;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (arr[ny][nx] == 1) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (cnt == zero_cnt)
		return max_visited;
	else
		return INF;
}

void DFS(int node, int cnt) {
	if (cnt == M) {
		min_time = min(min_time, BFS());
		return;
	}
	FOR(i, node, virus_cnt - 1) {
		ans[cnt] = i;
		DFS(i + 1, cnt + 1);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				v.push_back({ i, j });
			else if (arr[i][j] == 0)
				zero_cnt++;
		}
	}
	virus_cnt = v.size();
	zero_cnt += virus_cnt;
	DFS(0, 0);

	if (min_time == INF)
		cout << -1;
	else
		cout << min_time;

	return 0;
}