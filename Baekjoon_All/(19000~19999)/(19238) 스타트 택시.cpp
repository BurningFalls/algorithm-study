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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

struct NODE {
	int sy;
	int sx;
	int ey;
	int ex;
	int dist;
};

int N, M, fuel;
vector<vector<pii>> Map(21, vector<pii>(21));
vector<NODE> Pass(401);
vector<int> dy = { -1, 1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };

int Calc_Dist(int sy, int sx, int ey, int ex) {
	queue<pii> q;
	vector<vector<int>> visited(21, vector<int>(21, 0));
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == ey && x == ex)
			return visited[y][x] - 1;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (Map[ny][nx].first == -1) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return -1;
}

pii Find_Target(int sy, int sx) {
	queue<pii> q;
	vector<vector<int>> visited(21, vector<int>(21, 0));
	vector<pair<pii, int>> ans;
	int vis_end = INF;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x] > vis_end)
			break;
		if (Map[y][x].first == 1) {
			ans.push_back({ { y, x }, Map[y][x].second });
			vis_end = visited[y][x];
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (Map[ny][nx].first == -1) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (ans.empty())
		return { -1, -1 };
	sort(ALL(ans));

	return { ans[0].second, vis_end - 1 };
}

bool Func(int y, int x) {
	int cnt = 0;
	while (cnt < M) {
		pii tmp = Find_Target(y, x);
		int target = tmp.first;
		int dist = tmp.second;
		if (target == -1)
			return false;
		fuel -= dist;
		if (fuel < 0)
			return false;
		int dist2 = Pass[target].dist;
		if (dist2 == -1)
			return false;
		fuel -= dist2;
		if (fuel < 0)
			return false;
		fuel += dist2 * 2;
		y = Pass[target].ey;
		x = Pass[target].ex;
		Map[Pass[target].sy][Pass[target].sx] = { 0, 0 };
		cnt++;
	}
	return true;
}

int main() {
	FASTIO;
	int sy, sx;
	cin >> N >> M >> fuel;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int num;
			cin >> num;
			if (num == 0)
				Map[i][j] = { 0, 0 };
			else if (num == 1)
				Map[i][j] = { -1, -1 };
		}
	}
	cin >> sy >> sx;
	FOR(i, 1, M) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Map[a][b] = { 1, i };
		Pass[i] = { a, b, c, d, Calc_Dist(a, b, c, d) };
	}
	bool flag = Func(sy, sx);
	cout << (flag ? fuel : -1);

	return 0;
}