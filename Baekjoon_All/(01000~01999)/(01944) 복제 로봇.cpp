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
int Parent[252];
int Idx[51][51] = { 0, };
int Dist[252][252] = { 0, };
int visited[51][51] = { 0, };
vector<pair<int, pii>> v;

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

bool is_Same(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	return n1 == n2;
}

void Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	Parent[min(n1, n2)] = max(n1, n2);
}

void BFS(int sy, int sx) {
	queue<pii> q;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (Idx[y][x] != 0) {
			Dist[Idx[sy][sx]][Idx[y][x]] = visited[y][x] - 1;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (Map[ny][nx] == '1') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> N >> M;
	int idx = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
			if (Map[i][j] == 'S' || Map[i][j] == 'K') {
				idx++;
				Idx[i][j] = idx;
			}
		}
	}
	FOR(i, 1, idx) {
		Parent[i] = i;
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Idx[i][j] == 0) continue;
			memset(visited, 0, sizeof(visited));
			BFS(i, j);
		}
	}
	FOR(i, 1, idx) {
		FOR(j, i + 1, idx) {
			if (Dist[i][j] == 0) continue;
			v.push_back({ Dist[i][j], {i, j} });
		}
	}
	sort(ALL(v));
	int ans = 0;
	int cnt = 0;
	FOR(i, 0, LEN(v) - 1) {
		int dist = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		if (!is_Same(a, b)) {
			Union(a, b);
			ans += dist;
			cnt++;
		}
	}
	cout << ((cnt == idx - 1) ? ans : -1);

	return 0;
}