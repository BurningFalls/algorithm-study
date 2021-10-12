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
	int y;
	int x;
	int dir;
	int mir_cnt;
};

struct compare {
	bool operator() (NODE a, NODE b) {
		return a.mir_cnt > b.mir_cnt;
	}
};

int DT(int H, int W, vector<vector<char>>& Map) {
	int sy = 0, sx = 0, ey = 0, ex = 0;
	int cnt = 0;
	vector<int> dy = { -1, 1, 0, 0 };
	vector<int> dx = { 0, 0, -1, 1 };
	vector<vector<vector<int>>> mirror_cnt(H, vector<vector<int>>(W, vector<int>(4, INF)));
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			if (Map[i][j] == 'C') {
				cnt++;
				if (cnt == 1) {
					sy = i; sx = j;
				}
				else if (cnt == 2) {
					ey = i; ex = j;
				}
			}
		}
	}

	PQ<NODE, vector<NODE>, compare> pq;
	pq.push({ sy, sx, -1, -1 });
	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int dir = pq.top().dir;
		int mir_cnt = pq.top().mir_cnt;
		pq.pop();
		if (dir != -1 && mirror_cnt[y][x][dir] < mir_cnt)
			continue;
		FOR(i, 0, 3) {
			if (i == dir) continue;
			int ny = y;
			int nx = x;
			if (dir == -1) {
				mirror_cnt[ny][nx][i] = 0;
				pq.push({ ny, nx, i, 0 });
			}
			while (true) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W) break;
				if (Map[ny][nx] == '*') break;
				if (mirror_cnt[ny][nx][i] > mir_cnt + 1) {
					mirror_cnt[ny][nx][i] = mir_cnt + 1;
					pq.push({ ny, nx, i, mir_cnt + 1 });
				}
			}
		}
	}

	int mini = INF;
	FOR(i, 0, 3) {
		mini = min(mini, mirror_cnt[ey][ex][i]);
	}
	return mini;
}

int main() {
	FASTIO;
	int W, H;
	cin >> W >> H;
	vector<vector<char>> Map(H, vector<char>(W));
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			cin >> Map[i][j];
		}
	}
	cout << DT(H, W, Map);

	return 0;
}