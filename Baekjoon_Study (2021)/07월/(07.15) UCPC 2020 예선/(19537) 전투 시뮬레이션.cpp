#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

typedef struct _UNIT {
	int moving;
	int kind;
	int y;
	int x;
} UNIT;

int N, H, W, M, K;
int Rough[502][502];
int R[11];
UNIT unit[62502];

int dist[502][502];
int is_Unit[502][502];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool Enemy_Close(int node, int y, int x) {
	int my_kind = unit[node].kind;
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny > H - 1 || nx > W - 1) continue;
		if (is_Unit[ny][nx] == -1) continue;
		int other_kind = is_Unit[ny][nx];
		if (my_kind == other_kind) continue;
		return true;
	}
	return false;
}

bool Order(int u, int a, int b) {
	FOR(i, 0, H - 1)
		FOR(j, 0, W - 1)
			dist[i][j] = INF;

	int start_y = unit[u].y;
	int start_x = unit[u].x;
	int end_y = a;
	int end_x = b;
	if (is_Unit[end_y][end_x] != -1)
		return false;
	if (Rough[end_y][end_x] == -1)
		return false;

	priority_queue<pair<int, pii>> pq;
	pq.push({ 0, {start_y, start_x} });
	dist[start_y][start_x] = 0;
	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur_y = pq.top().second.first;
		int cur_x = pq.top().second.second;
		pq.pop();
		if (cur_y == end_y && cur_x == end_x)
			return true;

		if (!(cur_y == start_y && cur_x == start_x) &&
			Enemy_Close(u, cur_y, cur_x)) continue;

		FOR(i, 0, 3) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (next_y < 0 || next_x < 0 || next_y > H - 1 || next_x > W - 1) continue;
			if (Rough[next_y][next_x] == -1) continue;
			if (is_Unit[next_y][next_x] != -1 && unit[u].kind != is_Unit[next_y][next_x]) continue;
			int next_cost = cur_cost + Rough[next_y][next_x];
			if (next_cost > unit[u].moving) continue;
			if (next_cost < dist[next_y][next_x]) {
				dist[next_y][next_x] = next_cost;
				pq.push({ -next_cost, {next_y, next_x} });
			}
		}
	}
	return false;
}

int main() {
	FASTIO;
	memset(is_Unit, -1, sizeof(is_Unit));
	cin >> N >> H >> W;
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			cin >> Rough[i][j];
		}
	}
	FOR(i, 1, N) {
		cin >> R[i];
	}
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			Rough[i][j] = R[Rough[i][j]];
		}
	}

	cin >> M;
	FOR(i, 1, M) {
		int m, t, a, b;
		cin >> m >> t >> a >> b;
		unit[i] = { m, t, a, b };
		is_Unit[a][b] = t;
	}

	cin >> K;
	FOR(i, 1, K) {
		int u, a, b;
		cin >> u >> a >> b;
		if (Order(u, a, b)) {
			is_Unit[unit[u].y][unit[u].x] = -1;
			is_Unit[a][b] = unit[u].kind;
			unit[u].y = a;
			unit[u].x = b;
		}
	}

	FOR(i, 1, M) {
		cout << unit[i].y << " " << unit[i].x << "\n";
	}


	return 0;
}