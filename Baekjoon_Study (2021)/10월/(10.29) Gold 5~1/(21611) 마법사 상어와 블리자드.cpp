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
int Map[50][50];
vector<int> v;

void Set_Map() {
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { -1, 0, 1, 0 };
	int y = (N + 1) / 2, x = (N + 1) / 2;
	int moving = 1;
	int cnt = 0;
	int dir = 0;
	int idx = 0;
	while (true) {
		bool flag = true;
		FOR(mv, 1, moving) {
			y += dy[dir];
			x += dx[dir];
			if (idx == LEN(v)) {
				Map[y][x] = 0;
			}
			else {
				Map[y][x] = v[idx];
				idx++;
			}
			if (y == 1 && x == 1) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
		dir = (dir + 1) % 4;
		cnt++;
		if (cnt == 2) {
			moving++;
			cnt = 0;
		}
	}
}

void Move() {
	v.clear();
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { -1, 0, 1, 0 };
	int y = (N + 1) / 2, x = (N + 1) / 2;
	int moving = 1;
	int cnt = 0;
	int dir = 0;
	while (true) {
		bool flag = true;
		FOR(mv, 1, moving) {
			y += dy[dir];
			x += dx[dir];
			if (Map[y][x] != 0) {
				v.push_back(Map[y][x]);
			}
			if (y == 1 && x == 1) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
		dir = (dir + 1) % 4;
		cnt++;
		if (cnt == 2) {
			moving++;
			cnt = 0;
		}
	}
	Set_Map();
}

void Magic_Move(int d, int s) {
	int y = (N + 1) / 2;
	int x = (N + 1) / 2;
	int dy[5] = { 0, -1, 1, 0, 0 };
	int dx[5] = { 0, 0, 0, -1, 1 };
	FOR(i, 1, s) {
		y += dy[d];
		x += dx[d];
		if (y < 1 || y > N || x < 1 || x > N) break;
		Map[y][x] = 0;
	}
	Move();
}

vector<int> Boom_Move() {
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { -1, 0, 1, 0 };
	int y = (N + 1) / 2, x = (N + 1) / 2;
	int moving = 1;
	int cnt = 0;
	int dir = 0;
	int prev = -1;
	int num_cnt = 0;
	vector<int> boom_cnt(4, 0);
	vector<pii> tmp;
	while (true) {
		bool flag = true;
		FOR(mv, 1, moving) {
			y += dy[dir];
			x += dx[dir];
			
			if (prev != Map[y][x]) {
				if (num_cnt >= 4) {
					while (!tmp.empty()) {
						pii t = tmp.back();
						tmp.pop_back();
						boom_cnt[Map[t.first][t.second]]++;
						Map[t.first][t.second] = 0;
					}
				}
				tmp.clear();
				num_cnt = 1;
				tmp.push_back({ y, x });
			}
			else if (prev == Map[y][x]) {
				tmp.push_back({ y, x });
				num_cnt++;
			}
			prev = Map[y][x];

			if (y == 1 && x == 0) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
		dir = (dir + 1) % 4;
		cnt++;
		if (cnt == 2) {
			moving++;
			cnt = 0;
		}
	}
	Move();
	return boom_cnt;
}

void Change() {
	v.clear();
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { -1, 0, 1, 0 };
	int y = (N + 1) / 2, x = (N + 1) / 2;
	int moving = 1;
	int cnt = 0;
	int dir = 0;
	int prev = -1;
	int num_cnt = 0;
	while (true) {
		bool flag = true;
		FOR(mv, 1, moving) {
			y += dy[dir];
			x += dx[dir];
			if (prev != Map[y][x]) {
				if (num_cnt != 0) {
					v.push_back(num_cnt);
					v.push_back(prev);
				}
				num_cnt = 1;
			}
			else if (prev == Map[y][x]) {
				num_cnt++;
			}
			prev = Map[y][x];

			if (y == 1 && x == 0) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
		dir = (dir + 1) % 4;
		cnt++;
		if (cnt == 2) {
			moving++;
			cnt = 0;
		}
	}
	Set_Map();
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	int ans[4] = { 0, };
	FOR(m, 1, M) {
		int d, s;
		cin >> d >> s;
		Magic_Move(d, s);
		while (true) {
			vector<int> tmp = Boom_Move();
			if (tmp[1] + tmp[2] + tmp[3] == 0) {
				break;
			}
			FOR(i, 1, 3) {
				ans[i] += tmp[i];
			}
		}
		Change();
	}
	cout << ans[1] + 2 * ans[2] + 3 * ans[3];

	return 0;
}