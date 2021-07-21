#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

typedef struct _NODE {
	int y;
	int x;
	int moving;
} NODE;

int N, M;
int Sy, Sx, Ey, Ex;
int Map[102][102];
int dy0[4] = { -1, 1, 0, 0 };
int dx0[4] = { 0, 0, -1, 1 };
int dy1[2] = { -1, 1 };
int dx1[2] = { 0, 0 };
int dy2[2] = { 0, 0 };
int dx2[2] = { -1, 1 };
int dist[102][102][3];

struct cmp {
	bool operator()(pair<int, NODE> a, pair<int, NODE> b) {
		return a.first > b.first;
	}
};

void DT() {
	priority_queue<pair<int, NODE>, vector<pair<int, NODE>>, cmp> pq;
	pq.push({ 0, {Sy, Sx, 1} });
	dist[Sy][Sx][1] = 0;
	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur_y = pq.top().second.y;
		int cur_x = pq.top().second.x;
		int cur_mov = pq.top().second.moving;
		pq.pop();
		int next_mov = (cur_mov + 1) % 3;
		if (cur_mov % 3 == 0) {
			FOR(i, 0, 3) {
				int ny = cur_y + dy0[i];
				int nx = cur_x + dx0[i];
				if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
				if (Map[ny][nx] == -1) continue;
				int next_cost = cur_cost + Map[ny][nx];
				if (dist[ny][nx][next_mov] > next_cost) {
					dist[ny][nx][next_mov] = next_cost;
					pq.push({ -next_cost, {ny, nx, next_mov} });
				}
			}
		}
		else if (cur_mov % 3 == 1) {
			FOR(i, 0, 1) {
				int ny = cur_y + dy1[i];
				int nx = cur_x + dx1[i];
				if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
				if (Map[ny][nx] == -1) continue;
				int next_cost = cur_cost + Map[ny][nx];
				if (dist[ny][nx][next_mov] > next_cost) {
					dist[ny][nx][next_mov] = next_cost;
					pq.push({ -next_cost, {ny, nx, next_mov} });
				}
			}
		}
		else if (cur_mov % 3 == 2) {
			FOR(i, 0, 1) {
				int ny = cur_y + dy2[i];
				int nx = cur_x + dx2[i];
				if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
				if (Map[ny][nx] == -1) continue;
				int next_cost = cur_cost + Map[ny][nx];
				if (dist[ny][nx][next_mov] > next_cost) {
					dist[ny][nx][next_mov] = next_cost;
					pq.push({ -next_cost, {ny, nx, next_mov} });
				}
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			FOR(k, 0, 2) {
				dist[i][j][k] = INF;
			}
		}
	}
	cin >> Sy >> Sx >> Ey >> Ex;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	DT();
	int mini = INF;
	FOR(i, 0, 2) {
		mini = min(mini, dist[Ey][Ex][i]);
	}
	if (mini == INF)
		cout << -1;
	else
		cout << mini;

	return 0;
}