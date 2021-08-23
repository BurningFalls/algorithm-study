#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, M;
char Map[1001][1001];
int dist[1001][1001];
priority_queue<pair<int, pii>> pq;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void DT(int sy, int sx) {
	pq.push({ 0, { sy, sx } });
	dist[sy][sx] = 0;
	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (Map[y][x] == 'X') {
			int ny = y, nx = x;
			while (Map[ny][nx] == 'X')
				ny++;
			if (Map[ny][nx] == 'D') continue;
			int new_dist = cur_dist + 10;
			if (dist[ny][nx] > new_dist) {
				dist[ny][nx] = new_dist;
				pq.push({ -new_dist, { ny, nx } });
			}
			continue;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == 'D') continue;
			int new_dist = 0;
			if (i == 3) {
				if (Map[ny][nx] != 'L') continue;
				new_dist = cur_dist + 5;
			}
			else if (i == 2) {
				if (Map[y][x] != 'L') continue;
				new_dist = cur_dist + 5;
			}
			else {
				new_dist = cur_dist + 1;
			}
			if (dist[ny][nx] > new_dist) {
				dist[ny][nx] = new_dist;
				pq.push({ -new_dist, { ny, nx } });
			}
		}
	}
}

int main() {
	FASTIO;
	int sy = 0, sx = 0;
	int ey = 0, ex = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			dist[i][j] = INF;
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
			if (Map[i][j] == 'C') {
				sy = i;
				sx = j;
			}
			else if (Map[i][j] == 'E') {
				ey = i;
				ex = j;
			}
		}
	}
	DT(sy, sx);
	if (dist[ey][ex] == INF)
		cout << "dodo sad";
	else
		cout << dist[ey][ex];

	return 0;
}